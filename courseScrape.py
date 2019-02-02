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

# Create URL for each major catalog by concatenating major abbreviation
for current_major in majorURLs:
    current_url = majors_page + current_major + '.shtml'
    current_major = current_url
