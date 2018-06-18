import urllib as url

from bs4 import BeautifulSoup

page1 = url.open('https://en.wiktionary.org/wiki/Wiktionary:Frequency_lists/PG/2006/04/1-10000')

soup1 = BeautifulSoup(page1)

print(soup1.prettify)
