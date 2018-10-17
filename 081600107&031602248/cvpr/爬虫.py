import urllib.request
import re
url = "http://openaccess.thecvf.com/CVPR2018.py"    #CVPR����
head = "http://openaccess.thecvf.com/"      #������ַͷ����
data=open("D:\result.txt", 'w+',encoding='utf-8')       #������ļ�����Ϊ��׼�������
i=0
try:

    resp=urllib.request.urlopen(url)
    html=resp.read()
    html=html.decode()
    links=re.findall(r'content_cvpr_2018/html/.*.html',html)  #����������ַβ����
    # ���δ�ÿƪ���ĵ���ַ
    for a in links:
        resp = urllib.request.urlopen(head+a)      #������ַ
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