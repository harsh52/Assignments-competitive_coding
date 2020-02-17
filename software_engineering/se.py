import sqlite3

conn = sqlite3.connect('SE.db')
c1=conn.cursor()

c1.execute('CREATE TABLE IF NOT EXISTS genetic(sl_no REAL,gene TEXT,acid TEXT,per_a REAL,per_t REAL,per_g REAL,per_c REAL)')


count1 = 0
def per_calculation(amino,str_fin,count1):
	a=0
	t=0
	g=0
	c=0
	per_a = 0
	per_t = 0
	per_g = 0
	per_c = 0
	#print(amino)
	for i in str_fin:
		if i == 'a':
			a = a + 1
			#print("rfgv")
		elif i == 't':
			t = t + 1
		elif i == 'g':
			g = g + 1
		elif i == 'c':
			c = c + 1
	print(a,t,g,c)
	per_a = round((a/len(str_fin))*100,2)
	per_t = round((t/len(str_fin))*100,2)
	per_g = round((g/len(str_fin))*100,2)
	per_c = round((c/len(str_fin))*100,2) 
	#count1 = count1 + 1
	c1.execute("INSERT INTO genetic(sl_no,gene,acid,per_a,per_t,per_g,per_c) VALUES(?, ?, ?, ?, ?, ?, ?)",(count1,str_fin,amino,per_a,per_t,per_g,per_c))
	conn.commit()
	return 0


genetoacid =  {'ttt':'F','ttc':'F','tta':'L','ttg':'L',\
			   'ctt':'L','ctc':'L','cta':'L','ctg':'L',\
               'att':'I','atc':'I','ata':'I','atg':'M',\
               'gtt':'V','gtc':'V','gta':'V','gtg':'V',\
               'tct':'S','tcc':'S','tca':'S','tcg':'S',\
               'cct':'P','ccc':'P','cca':'P','ccg':'P',\
               'act':'T','acc':'T','aca':'T','acg':'T',\
               'gct':'A','gcc':'A','gca':'A','gcg':'A',\
               'tat':'Y','tac':'Y','cat':'H','cac':'H',\
               'caa':'Q','cag':'Q','aat':'N','aac':'N',\
               'aaa':'K','aag':'K','gat':'N','gac':'N',\
               'gaa':'E','gag':'E','tgt':'C','tgc':'C',\
               'tgg':'W','cgt':'R','cgc':'R','cga':'R',\
               'cgg':'R','aga':'R','agg':'R','agt':'S',\
               'agc':'S','ggt':'G','ggc':'G','gga':'G',\
               'ggg':'G'
	
}
amino=""
str1 = ''
str_fin=''
list1 = []
count = 0
amino_file = open("test_demo.txt", "w")
with open("test.txt","r") as f:
	
	#f.content = f.read(1)
	while True:
		f.content = f.read(1)
		if(len(f.content) ==0):
			break
		if(f.content==">"):
			amino=''
			#print(str_fin,end="9999\n")
			str_fin = ''
			list1.append(str(f.readline()))
		else:
			
			if(f.content=='a' or f.content=='t' or f.content=='g' or f.content=='c'):
				str1 = str1 + str(f.content)
				#str_fin = str_fin + str1
				#print(str_fin)
			else:
				continue

			count = count + 1
			if(count == 3):
				count=0
				if(str1=="taa" or str1 == "tag" or str1 == "tga"):
					#print("*\n",end='')
					amino_file.write(amino)
					amino_file.write("*\n")
					#print(amino,end='####')
					count1 = count1 + 1
					per_calculation(amino,str_fin,count1)
					#c.execute("INSERT INTO genetic(gene,acid) VALUES(?, ?)",(str_fin,amino))
					#conn.commit()
					f.content = f.read(1)
					str1=''
				else:
					str_fin = str_fin + str1
					amino= amino + str(genetoacid[str1])
					#print(amino,end='')
					#amino_file.write(amino)
					#f.content = f.read(1)
					str1=''

	#f.content = f.read(size_to_read)
	#amino_file.write(amino)