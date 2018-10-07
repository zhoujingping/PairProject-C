# -*- coding:UTF-8 -*-
from urllib import request
from bs4 import BeautifulSoup
import re
import sys
if __name__ == "__main__":
    #创建txt文件
    file = open('.\\result.txt', 'w', encoding='utf-8')
    target_url = 'http://openaccess.thecvf.com/CVPR2018.py'
    #User-Agent
    head = {}
    head['User-Agent'] = 'Mozilla/5.0 (Linux; Android 4.1.1; Nexus 7 Build/JRO03D) AppleWebKit/535.19 (KHTML, like Gecko) Chrome/18.0.1025.166  Safari/535.19'
    target_req = request.Request(url = target_url, headers = head)
    target_response = request.urlopen(target_req)
    target_html = target_response.read().decode('utf-8')
    #创建BeautifulSoup对象
    listmain_soup = BeautifulSoup(target_html,'lxml')
    #搜索文档树,找出div标签中id为content的所有子标签
    chapters = listmain_soup.find_all('div',id = 'content')
    #使用查询结果再创建一个BeautifulSoup对象,对其继续进行解析
    download_soup = BeautifulSoup(str(chapters), 'lxml')
    #计算论文个数
    numbers = len(download_soup.dl.contents) 
    index = 0
    #开始记录内容标志位,只要正文卷下面的链接,最新章节列表链接剔除
    begin_flag = True
    #遍历dl标签下所有子节点
    for child in download_soup.dl.children:
        #滤除回车
        if(child != '\n' and child.name != "dd"):
            print(child.name)
            #爬取链接下载链接内容
            if begin_flag == True and child.a != None:
                download_url = "http://openaccess.thecvf.com/"  +  child.a.get('href')
                download_req = request.Request(url = download_url, headers = head)
                download_response = request.urlopen(download_req)
                download_html = download_response.read().decode('utf-8')
                download_name = child.a.string
                soup_texts = BeautifulSoup(download_html, 'lxml')
                #改
                texts = soup_texts.find_all('div',id = 'content')
                soup_text = BeautifulSoup(str(texts), 'lxml')
                write_flag = True
                file.write(str(index) +'\n')
                #将爬取内容写入文件
                file.write('Title: '+download_name + '\n')
                #作者信息
#                authors=soup_text.find('div',id = 'authors')
#                file.write('Title: 'authors.string + '\n')
                
                abstract=soup_text.find('div',id = 'abstract')
                file.write('Abstract: '+abstract.string[1:] + '\n')
                
                file.write('\n\n')
                #打印爬取进度
                #刷新输出
                sys.stdout.flush()
                index += 1
    file.close()
   