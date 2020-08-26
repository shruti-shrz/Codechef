import requests
import argparse
import sqlite3
import os
import csv

parser = argparse.ArgumentParser(description='analyze codechef problem')
parser.add_argument('-d', '--database', default='analyze.db')
parser.add_argument('-f', '--fill', default='../dataset/analyzer.csv')
args = parser.parse_args()

conn = sqlite3.connect(args.database)
c = conn.cursor()


with open(args.fill) as file:
    reader = csv.reader(file,delimiter=',')
    lc = 0
    for row in reader:
        if lc!=0:
            if(row[7]=='C++14'):
                t = (row[0],'C++14')
                c.execute('SELECT code FROM programs WHERE program_id =?',t)
                result = c.fetchone()
                if result != None:
                    # print(row[0])
                    for x in result:
                        print(x)
        lc += 1

conn.close()

# c.execute('SELECT code FROM programs WHERE program_id =34854309')
# result = c.fetchone()
# if result != None:
#     print("Nope this aint the place")
# for x in result:
#     print(x)