#!/usr/local/bin/python

import csv
wires = [[[4,8,12,16],[4,7,11,13],[4,6,10,15],[4,5,9,14]],
			[[3,8,11,15],[3,7,12,14],[3,6,9,16],[3,5,10,13]],
			[[2,8,10,14],[2,7,9,15],[2,6,12,13],[2,5,11,16]],
			[[1,8,9,13],[1,7,10,16],[1,6,11,14],[1,5,12,15]]]

results = []
for c in range(1,4):
	for x in range(0,4):
		results.append([])
		for y in range(0,4):
			results[x].append([])
			for z in range(0,4):
				results[x][y].append([])
				results[x][y][z]=['%d%d%d' % (x+1, y+1, z+1)]
				leads = wires[x][y][:]
				for i in range(z):
					newFront = leads.pop()
					leads.insert(0, newFront)
				results[x][y][z].append(leads[c])
				results[x][y][z].append(leads[0])
header = ['LED','Cathode','Red','Green','Blue']
leadsFile = open("new_leads.csv",'wb')
wr = csv.writer(leadsFile, dialect='excel')
wr.writerow(header)
for x in range(0,4):
	for y in range(0,4):
		wr.writerows(results[x][y])
leadsFile.close()


