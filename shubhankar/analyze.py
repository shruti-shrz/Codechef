#!/usr/bin/env python
# coding: utf-8

# In[ ]:


from bs4 import BeautifulSoup
from retrying import retry
import requests
import argparse
import sqlite3
import csv
import os

parser = argparse.ArgumentParser(description='Scrape codechef problem')
parser.add_argument('problem')
parser.add_argument('-l', '--language', default='All')
parser.add_argument('-s', '--status', default='All')
parser.add_argument('-b', '--start', type=int, default=0)
args = parser.parse_args()


languages = {'C': 11,  'JAVA': 10, 'PYTH': 4, 'PYTH3': 116, 'C++':44}
statuses  = {'WA': 14, 'AC': 15, 'TLE': 13, 'RTE': 12, 'CTE': 11}

payload = { 'language': 'All','status': 'All','sort_by': 'Date/Time','sorting_order': 'asc','handle': '' }

if args.status is not 'All':
    payload['status'] = statuses[args.status]

if args.language is not 'All':
    payload['language'] = languages[args.language]

@retry(wait_exponential_multiplier=1000, wait_exponential_max=10000, stop_max_attempt_number=5)
def retrying_get(url, params=None):
    r = requests.get(url, params=params)

    if r.status_code != requests.codes.ok:
        print ('Failed to get %s: HTTP %d' % (url, r.status_code))
        raise IOError('Unexpected response, expected OK')

    return r

r = retrying_get('https://www.codechef.com/status/%s' % args.problem, params=payload)
soup = BeautifulSoup(r.text, 'html.parser')

# Get the number of pages
try:
    pages = int(soup.find('div', class_='pageinfo').get_text().split()[-1])
except AttributeError:
    pages = 1


with open('analyzer.csv', 'a', newline='') as file:
    writer = csv.writer(file)
    # writer.writerow(["program_id", "datetime","star", "user", "result", "time", "memory", "language", "problem_code"])
    # For each page
    for page in range(args.start, pages):
        print ('Page %d/%d' % (page + 1, pages))
        if(page!=0):
            payload['page'] = page + 1
        r = retrying_get('https://www.codechef.com/status/%s' % args.problem, params=payload)
        soup = BeautifulSoup(r.text, 'html.parser')

        for item in soup.find_all('tr', class_='\\"kol\\"'):
            result = [item.find_all('td')[0].get_text(),
                    item.find_all('td')[1].get_text(),
                    item.find_all('td')[2].find('span').get_text()[:-1] if item.find_all('td')[2].find('span') else 0,
                    item.find_all('td')[2].find('a')['title'],
                    item.find_all('td')[3].find('span')['title'],
                    item.find_all('td')[4].get_text(),
                    item.find_all('td')[5].get_text(),
                    item.find_all('td')[6].get_text(),
                    args.problem]
            
            print ('Processing', result[0])
            writer.writerow(result)



# In[ ]:




