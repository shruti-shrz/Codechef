# import requests
# import json
# from bs4 import BeautifulSoup
# # url = "https://www.codechef.com/submissions"
# # plain_html_text = requests.get(url)
# # soup = BeautifulSoup(plain_html_text.text, "html.parser")
# # #sol = soup.findAll('td',{'class':'centered word-break-unset'})
# # i=0
# # for sol in soup.findAll('td',{'class':'centered word-break-unset'}):
# # 	k = sol.find('a')
# # 	l = k['href']
# # 	print(l)
# # 	url2 = "https://www.codechef.com" + l
# # 	plain_html_text2 = requests.get(url2)
# # 	soup2 = BeautifulSoup(plain_html_text2.text, "html.parser")
# # 	m = soup2.find('div',{'class':'ace_content'})
# # 	print(m)
# # 	i=i+1
# # 	if i==20:
# # 		break
# url = "https://www.codechef.com/viewsolution/34866751"
# plain_html_text = requests.get(url)
# soup = BeautifulSoup(plain_html_text.text, "html.parser")
# for j in soup.findAll('div',{'class':'para-div'}):
# 	k = j.find('p')
# 	print(j)
# 	print(k)


# for k in soup.findAll('div',{'class':'ace_line'}):
# 	for m in k.findAll('span'):
# 		print(l)
#C:\Users\Shruti priya\Desktop\Solution
#//*[@id="content"]/div/div/div[2]/table/tbody/tr[1]/td[10]/ul/li/a
#//*[@id="content"]/div/div/div[2]/table/tbody/tr[1]/td[10]/ul/li/a
#//*[@id="content"]/div/div/div[2]/table/tbody/tr[2]/td[10]/ul/li/a
from selenium import webdriver
driver = webdriver.Chrome("D:/Download/chromedriver_win32/chromedriver.exe")
driver.get("https://www.codechef.com/submissions")
solutions = driver.find_elements_by_xpath("/html/body/center/center/table/tbody/tr/td/div/div/div/div/div[2]/div/div/div/div/div[2]/table/tbody/tr")
targets = {}
tag = []
i=1
for line in solutions:
	k = "/html/body/center/center/table/tbody/tr/td/div/div/div/div/div[2]/div/div/div/div/div[2]/table/tbody/tr["
	k+=str(i)
	k+="]/td[9]"
	#print(k)
	targets[line.find_elements_by_tag_name('a')[3].get_attribute('href')] =driver.find_elements_by_xpath(k)[0].text
	tag.append(line.find_elements_by_tag_name('a')[3].get_attribute('href'))
	i=i+1
print(targets)
#driver.quit()
for i in range(len(tag)):
	driver = webdriver.Chrome("D:/Download/chromedriver_win32/chromedriver.exe")
	if targets[tag[i]] == "C++14":
		driver.get(tag[i])
		codes = driver.find_elements_by_class_name('ace_line_group')
		filename = "C:/Users/Shruti priya/Desktop/Solution/codef" + str(i) +".cpp"
		f = open(filename,"w+")
		for code in codes:
			f.write(code.text+"\n")
		f.close()
		driver.quit()
	driver.quit()