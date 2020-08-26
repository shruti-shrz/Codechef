# import os
# import pandas as pd

# csv = pd.read_csv('../dataset/analyzer.csv')
# csv['# of recursions'] = 0
# csv['# of iteration'] = 0

# csv.to_csv('../dataset/analyzer.csv',index=False)

import subprocess
import sqlite3
import os

# conn = sqlite3.connect('analyze.db')
# c = conn.cursor()


# c.execute('SELECT code FROM programs WHERE program_id =35649621')
# result = c.fetchone()
# if result != None:
#     # print("Nope this aint the place")
#     for x in result:
#         print(x)
#         subprocess.call(["r", x],shell=True)

subprocess.call(['dir'],shell=True)