import requests
import argparse
import sqlite3
import os
import csv
import subprocess
import time
parser = argparse.ArgumentParser(description='analyze codechef problem')
parser.add_argument('-d', '--database', default='analyze.db')
parser.add_argument('-f', '--fill', default='../dataset/analyzer.csv')
args = parser.parse_args()

conn = sqlite3.connect(args.database)
c = conn.cursor()

flag =0;
with open(args.fill) as file:
    reader = csv.reader(file,delimiter=',')
    lc = 0
    for row in reader:
        if lc!=0:
            if(row[7]=='C++14'):
                t = (row[0],)
                c.execute('SELECT code FROM programs WHERE program_id =?',t)
                result = c.fetchone()
                # if result != None:
                #     flag=flag+1
                #     if flag<=2:
                #         for x in result:
                #             print(x)
                if result != None:
                    for x in result:
                        file1 = open("output.cpp","w+")
                        file1.writelines(x)
                        file1.close()
                        data, temp = os.pipe()
                        os.write(temp, bytes("5 10\n", "utf-8"));
                        os.close(temp)
                        args = []
                        args.append('./r')
                        args.append('output.cpp')
                        num = subprocess.check_output(args,stdin=data,shell=True)
                        print(num.decode("utf-8"))
                        # print(num)
                        # writer.writerow(row)
        lc += 1

conn.close()

# c.execute('SELECT code FROM programs WHERE program_id =34854309')
# result = c.fetchone()
# if result != None:
#     print("Nope this aint the place")
# for x in result:
#     print(x)