import urllib.request
import re
url = "http://openaccess.thecvf.com/CVPR2018.py"    #CVPR官网
head = "http://openaccess.thecvf.com/"      #论文网址头部分
data=open("D:\result.txt", 'w+',encoding='utf-8')       #打开输出文件并改为标准输出编码
i=0
try:

    resp=urllib.request.urlopen(url)
    html=resp.read()
    html=html.decode()
    links=re.findall(r'content_cvpr_2018/html/.*.html',html)  #所有论文网址尾部分
    # 依次打开每篇论文的网址
    for a in links:
        resp = urllib.request.urlopen(head+a)      #论文网址
        html = resp.read()
        html = html.decode()
        #title
        t1 = re.search(r'\"papertitle\">',html)
        t1 = html[t1.end()+1:]
        t2 = re.search(r'</div>',t1)
        title = t1[:t2.start()]
        print(i, file=data)
        print("Title:", title, file=data)
        #abstract
        a1 = re.search(r'\"abstract\"', html)
        a1 = html[a1.end()+3:]
        a2 = re.search(r'</div>', a1)
        abstract = a1[:a2.start()]
        print("Abstract:", abstract,end="\n\n\n",file=data)
        i=i+1
    data.close()
except Exception as e:
    print(e)