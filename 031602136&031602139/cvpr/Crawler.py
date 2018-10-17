#!/usr/bin/env python
# -*- coding: utf-8 -*-

import requests
from lxml import etree
import sys  
import io

reload(sys)  
sys.setdefaultencoding('utf-8')  
 
#我们抓取的页面链接
originURL='http://openaccess.thecvf.com/CVPR2018.py'

#用requests库的get方法下载网页
originText=requests.get(originURL).text

#解析网页并且定位
originObj=etree.HTML(originText)

paperName=originObj.xpath('//*[@id="content"]/dl/dt/a/text()')
paperURL=originObj.xpath('//*[@id="content"]/dl/dt/a/@href')
#author=originObj.xpath('//*[@id="content"]/dl/dd/div/div/text()[2]')
pdfLink=originObj.xpath('//*[@id="content"]/dl/dd/a[1]/@href')

author=[]
abstract=[]

for iterURL in paperURL:
	iterURL='http://openaccess.thecvf.com/'+iterURL
	iterText=requests.get(iterURL).text
	iterObj=etree.HTML(iterText)
	iterAuthor=iterObj.xpath('//*[@id="authors"]/b/i/text()')
	iterAbstract=iterObj.xpath('//*[@id="abstract"]/text()')
	iterAbstract[0]=iterAbstract[0].replace('\n','')
	author.append(iterAuthor[0])
	abstract.append(iterAbstract[0])

#输出到文件
outFile = io.open('result.txt', 'w', encoding='utf-8')
for i in range(len(paperName)):
	outFile.write(str(i)+"\n")
	outFile.write("Title: "+paperName[i]+"\n")
	#outFile.write("Authors: "+author[i]+"\n")
	outFile.write("Abstract: "+abstract[i])
	#outFile.write("PDF_LINK: "+"http://openaccess.thecvf.com/"+pdfLink[i])
	if i <> (len(paperName)-1):
		outFile.write("\n\n\n")
outFile.close()
 