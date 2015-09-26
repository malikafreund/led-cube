#!/usr/local/bin/python

import csv
wires = [[[4,8,12,16],[4,7,11,13],[4,6,10,15],[4,5,9,14]],
			[[3,8,11,15],[3,7,12,14],[3,6,9,16],[3,5,10,13]],
			[[2,8,10,14],[2,7,9,15],[2,6,12,13],[2,5,11,16]],
			[[1,8,9,13],[1,7,10,16],[1,6,11,14],[1,5,12,15]]]

results = []
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
			results[x][y][z].extend(leads)
header = ['LED','Cathode','Red','Green','Blue']
leadsFile = open("led_corrected_leads.csv",'wb')
wr = csv.writer(leadsFile, dialect='excel')
wr.writerow(header)
for x in range(0,4):
	for y in range(0,4):
		wr.writerows(results[x][y])
leadsFile.close()

mappingFile = open("mapping_file.txt",'w')
codingFile = open("coding_file.txt",'w')
counter = 4
ind_counter = 0
for i in 'bgr':
	for x in range(0,4):
		for y in range(0,4):
			for z in range(0,4):
				z = z+3
				z = z%4
				mappingFile.write("{}{} {},{}\n".format(i, results[x][y][z][0], results[x][y][z][counter], results[x][y][z][1]))
				codingFile.write('if (_cube_buffer[  {}] != 0)flushElement(copy_frame, {}, {},_cube_buffer[  {}]);\n'\
					.format(ind_counter, results[x][y][z][counter], results[x][y][z][1], ind_counter))
				ind_counter = ind_counter + 1
	counter=counter - 1
mappingFile.close()
codingFile.close()

