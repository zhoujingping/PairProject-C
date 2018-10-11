
import re
import sys
from bs4 import BeautifulSoup
import urllib.request
homeurl="http://openaccess.thecvf.com/CVPR2018.py"
file = urllib.request.urlopen(homeurl).read()
page = BeautifulSoup(file , "html.parser")  
f=open(r'C:\Users\csxcs\Desktop\result.txt','w',encoding='utf-8')


#title=re.findall('<div id="papertitle">\n\s*(.*?)\n\s*</div>',page.decode('utf-8'),re.S)
#print(title)
#print(title[0])
#abstract=re.findall('<div id="abstract">\n\s*(.*?)\n\s*</div>',page.decode('utf-8'),re.S)
#print(abstract)
cnt=0
for link in page.find_all("dt",class_="ptitle"):
    uuu=link.find('a')
    url=str(uuu.get('href'))
    #print(type(url))
    urll="http://openaccess.thecvf.com/"
    urll=urll+url
    print(urll)
    file1 = urllib.request.urlopen(urll).read()
    page1 = BeautifulSoup(file1 , "html.parser")  
    title = re.findall('<div id="papertitle">\n\s*(.*?)\n\s*</div>',page1.decode('utf-8'),re.S)
    abstract=re.findall('<div id="abstract">\n\s*(.*?)\n\s*</div>',page1.decode('utf-8'),re.S)
    f.write(str(cnt))
    f.write('\n')
    
    f.write("Title: "+title[0])
    f.write('\n')
    f.write("Abstract: "+abstract[0])
    if urll!="http://openaccess.thecvf.com/content_cvpr_2018/html/Chen_CartoonGAN_Generative_Adversarial_CVPR_2018_paper.html":
        f.write('\n')
        f.write('\n')
        f.write('\n')
    cnt=cnt+1

f.close()


    







