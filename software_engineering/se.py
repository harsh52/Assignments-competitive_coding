import sqlite3

conn = sqlite3.connect('SE.db')
c=conn.cursor()

c.execute('CREATE TABLE IF NOT EXISTS genetic(gene TEXT,acid TEXT)')


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
					c.execute("INSERT INTO genetic(gene,acid) VALUES(?, ?)",(str_fin,amino))
					conn.commit()
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