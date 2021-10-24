import csv
import sys



def main():
	with open('databases/small.csv') as csvfile:
		csvreader = csv.reader(csvfile, delimiter=' ', quotechar='|')
		for row in csvreader:
			print(', '.join(row))


if __name__ == "__main__":
    main()


