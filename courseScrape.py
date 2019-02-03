# This code was created based on the web scraping guide found at
# https://medium.freecodecamp.org/how-to-scrape-websites-with-python-and-beautifulsoup-5946935d93fe

# import libraries
import urllib2
from bs4 import BeautifulSoup
import csv


majorNames = []
majorURLs = []

# specify the url
majors_page = 'http://ems.csuchico.edu/APSS/schedule/spr2019/'

# query the website and return the html to the variable 'major_list_page'
major_list_page = urllib2.urlopen(majors_page)

# parse the html using beautiful soup and store in variable 'soup'
soup = BeautifulSoup(major_list_page, 'html.parser')

# Take out the <div> of name and get its value
majorNames = soup.findAll('dd', attrs={'class': 'indexletterdd'})

# Parse each major name, extracting the 4-letter abbreviation
for course in majorNames:
    name = course.text.strip() # strip() is used to remove starting and trailing
    name_length = len(name)
    name = name[(name_length - 4):]
    majorURLs.append(name)

# Initial row of csv
with open('data.csv',mode='w') as courseFile:
    courseWriter = csv.writer(courseFile,delimiter =',')
    courseWriter.writerow(['Course','Major','CourseNum','Section','Instrucors','Days','Time','Building'])

for current_major in majorURLs:

    current_url = majors_page + current_major + '.shtml'

    #list variables containing web data
    courseNames = []
    classNum = []
    sectionNum = []
    instructors = []
    classDay = []
    classTime = []
    classBldg = []

    #
    open_page = urllib2.urlopen(current_url)

    #
    parse_page = BeautifulSoup(open_page,'html.parser')

    #Find all necessarry attributes
    courseNames = parse_page.findAll('td',attrs={'class' : 'title'})
    classNum = parse_page.findAll('td',attrs={'class':'cat_num'})
    sectionNum = parse_page.findAll('td',attrs={'class':'sect'})
    instructors = parse_page.findAll('td',attrs={'class':'Instructor'})
    classDay = parse_page.findAll('td',attrs={'class':'days'})
    classTime = parse_page.findAll('td',attrs={'class':'time'})
    classBldg = parse_page.findAll('td',attrs={'class':'loc'})
	
    #Write each data set to csv
    with open('data.csv',mode='a') as courseFile:
    	courseWriter = csv.writer(courseFile,delimiter =',')
    	for i in range(len(courseNames)):
            instructor = instructors[i].text.strip()
            time = classTime[i].text.strip()
    		#if instructor does not exist, class does not exist
            if instructor and time:
                course = courseNames[i].text.strip()
                number = classNum[i].text.strip()
                section = sectionNum[i].text.strip()
                day = classDay[i].text.strip()
                building = classBldg[i].text.strip()
                courseWriter.writerow([course,current_major,number,section,instructor,day,time,building])
