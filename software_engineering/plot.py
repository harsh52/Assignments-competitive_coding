import sqlite3
import matplotlib.pyplot as plt
from matplotlib import style
#style.use('ggplot')
conn = sqlite3.connect('SE2.db')
c1=conn.cursor()

def read_from_db():
    c1.execute("SELECT per_a,per_c,per_d,per_e,per_f,per_g,per_h,per_i,per_j,per_k,per_l,per_m,per_n,per_p,per_q,per_r,per_s,per_t,per_v,per_w,per_y FROM genetic")
    data = c1.fetchall()
    print(data)
    per=[]
    
    y1=data[0]
    #y2=data[3]
    #y3=data[4]
    x=['a','c','d','e','f','g','h','i','j','k','l','m','n','p','q','r','s','t','v','w','y']
    plt.bar(x,y1,'c',label='row 0')
   # plt.plot(x,y2,'g',label='row 1')
   # plt.plot(x,y3,'r',label='row 2')
    plt.title('percentage distribution')
    plt.ylabel('percentage')
    plt.xlabel('element of amino acid')
    plt.legend()
    plt.show()


read_from_db()
