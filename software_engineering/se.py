
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

amino_file = open("amino_file.txt", "w")
with open("Ecol_K12_MG1655_.ena","r") as f:
	size_to_read = 3
	f.content = f.read(size_to_read)
	while len(f.content)>0:
		for gc,amino in genetoacid.items():
			if gc == f.content:
				print(amino,end='')
				amino_file.write(amino)
				
			elif f.content=="taa" or f.content == "tag" or f.content == "tga":
				print("Stop\n",end='')
				amino_file.write("Stop\n")
				#f.content = f.read(size_to_read)
				break
		f.content = f.read(size_to_read)