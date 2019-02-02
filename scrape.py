import urllib2
from bs4 import BeautifulSoup
import csv

#declare url
url = "http://ems.csuchico.edu/APSS/schedule/spr2019/CSCI.shtml"


#list variables containing web data
courseNames = []
classNum = []
sectionNum = []
instructors = []
classDay = []
classTime = []
classBldg = []

#
page = urllib2.urlopen(url)

#
soup = BeautifulSoup(page,'html.parser')

#Find all necessarry attributes
courseNames = soup.findAll('td',attrs={'class' : 'title'})
classNum = soup.findAll('td',attrs={'class':'cat_num'})
sectionNum = soup.findAll('td',attrs={'class':'sect'})
instructors = soup.findAll('td',attrs={'class':'Instructor'})
classDay = soup.findAll('td',attrs={'class':'days'})
classTime = soup.findAll('td',attrs={'class':'time'})
classBldg = soup.findAll('td',attrs={'class':'loc'})

#Write each data set to csv
with open('data.csv',mode='w') as courseFile:
	courseWriter = csv.writer(courseFile,delimiter =',')
	courseWriter.writerow(['Course','CourseNum','Section','Instrucors','Days','Time','Building'])
	for i in range(len(courseNames)):
		time = classTime[i].text.strip()
		#if time does not exist, class does not exist
		if time:
			course = courseNames[i].text.strip()
			number = classNum[i].text.strip()
			section = sectionNum[i].text.strip()
			instructor = instructors[i].text.strip()
			day = classDay[i].text.strip()	
			building = classBldg[i].text.strip()
			courseWriter.writerow([course,number,section,instructor,day,time,building])	
