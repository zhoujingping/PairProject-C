import requests
from lxml import etree
from retrying import retry
@retry(stop_max_attempt_number=3)     # 设置超时重新连接 次数3
def get( url ):
    response = requests.get(url=url,timeout=3)
    return response.content.decode()

response = get("http://openaccess.thecvf.com/CVPR2018.py")
selector = etree.HTML(response)
links=selector.xpath('//dt[@class = "ptitle"]/a/@href')
titles = selector.xpath('//dt[@class = "ptitle"]/a/text()')
fb = open('result.txt','w',encoding='utf-8')
for i in range(len(links)):
    response2 = get("http://openaccess.thecvf.com/"+links[i])
    selector2 = etree.HTML(response2)
    abstract = selector2.xpath('//div[@id = "abstract"]/text()')[0][1:]
    fb.write('%s' % i + '\n' + 'Title: %s' % titles[i] + '\n' + 'Abstract: ' + abstract + '\n\n\n')
fb.close()