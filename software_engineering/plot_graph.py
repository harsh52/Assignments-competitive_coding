import sqlite3

conn = sqlite3.connect('SE.db')
c1=conn.cursor()

def read_from_db():
	c1.execute("SELECT per_a,per_t,per_g,per_c FROM genetic")
	data = c1.fetchall()
	for i in data:
		print(i)


read_from_db()