from csv import reader, DictReader
from sys import argv, exit

#require first command line argument as csv file contains STR counts
#require second command line argument as text file contains DNA sequence to identify
#usage - python dna.py databases/large.csv sequences/5.txt
#output -> Lavender


def main():

	#check correct number of command line argument, ensure correct usage
	if len(argv) != 3:
		exit("Usage: python dna.py data.csv sequence.txt")


	#open the csv file and read into memory called reader, and it store into databases.
	with open(argv[1], "r") as csv_file:
		reader = DictReader(csv_file)
		databases = list(reader)

	#open the DNA sequence and read its contents into memory called sequences.
	with open(argv[2], "r") as seqences_file:
		sequences = seqences_file.read()


	max_counts = []

	#compare the STR counts against each row in the csv file.
	for i in range(1, len(reader.fieldnames)):
		STR = reader.fieldnames[i]
		max_counts.append(0)

		#iterate sequences, and check STR are matched
		for j in range(len(sequences)):
			STR_count = 0

			#If STR are matched, start counting repeats
			if sequences[j:(j + len(STR))] == STR:
				k = 0
				while sequences[(j + k):(j + k + len(STR))] == STR:
					STR_count += 1
					k += len(STR)
				#update max_counts
				if STR_count > max_counts[i - 1]:
					max_counts[i - 1] = STR_count




	#compare against data
	for i in range(len(databases)):
		matches = 0
		for j in range(1, len(reader.fieldnames)):
			if int(max_counts[j - 1]) == int(databases[i]  [reader.fieldnames[j]]):
				matches += 1
			if matches == (len(reader.fieldnames) - 1):
				print(databases[i]['name'])
				exit(0)

	print("No match")



if __name__ == "__main__":
	main()


