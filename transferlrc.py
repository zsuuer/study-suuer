import os, re
with open('C:/Users/suuer/Downloads/qlx.lrc','rb') as f:    #将lrc文件转化为txt文件
    a=f.read()
    a=a.decode('utf-8')
    with open('C:/Users/suuer/Downloads/qlx.txt','w',1,'utf-8') as f1:
        f1.write(a)
        f1.close()
    f.close()
with open('C:/Users/suuer/Downloads/qlx.txt', 'r', 1, 'utf-8') as f:    #对txt文件进行读取，通过正则表达式分别进行分类
    a = f.readlines()
    table = {}
    print(a)
    pattern = re.compile(u'[\u4e00-\u9fa5 \u2E80-\uFE4F\u0020\u3000-\u303F]+')
    for x in a:
        b = re.findall('\[\d\d\:\d\d\.\d\d\]', x)
        if b :
            c = re.search(pattern, x)
            if c is not None:
                for i in b:
                    print(i)
                    print(c.group())
                    table[i]=c.group()
        else:
            d=re.search('ti|ar|al|by|offset',x)
            if d is not None:
                    h=re.search(pattern,x)
                    if h is not None:
                        table[d.group()]=h.group()
                    else:
                        h = re.search('\:([\d\w]{3})', x)
                        table[d.group()] = h.group(1)
print(table)
sort_a=[]
for x in table:             #将排序好的文件进行写入sortqlx.txt文件
    if re.match('\[\d\d\:\d\d\.\d\d\]', x):
        sort_a.append(x)
print(sort_a)
sort_a=sorted(sort_a)
print(sort_a)
with open('C:/Users/suuer/Downloads/sortqlx.txt', 'w', 1, 'utf-8') as f:
    f.write('ti:'+ table['ti']+'\n')
    f.write('ar:' + table['ar']+'\n')
    f.write('al:' + table['al'] + '\n')
    f.write('by:' + table['by'] + '\n')
    f.write('offset:' + table['offset'] + '\n')
    for i in sort_a:
        f.write(table[i]+'\n')
    f.close()

