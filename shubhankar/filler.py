import requests
import argparse
import sqlite3
import os
import csv

parser = argparse.ArgumentParser(description='Scrape codechef problem')
parser.add_argument('-d', '--database', default='analyze.db')
parser.add_argument('-f', '--fill', default='../dataset/analyzer.csv')
args = parser.parse_args()

conn = sqlite3.connect(args.database)
c = conn.cursor()

c.execute('SELECT code FROM programs WHERE program_id = 34852142')

result = c.fetchall()

for x in result:
    print(x[0])