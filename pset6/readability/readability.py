import cs50

def main():
 
    #prompt to get User Input as string type
    text = cs50.get_string("Text: ")
    
    #Declare the var which include number of elements in text.
    num_letters = count_letters(text)
    num_words = count_words(text)
    num_sentences = count_sentences(text)
    
    #Calculate index
    L = num_letters / float(num_words) * 100
    S = num_sentences / float(num_words) * 100
    
    index = round(0.0588 * L - 0.296 * S - 15.8)
    print(index)
    
    if (index >= 16):
        print("Grade 16+")
    elif (index < 1):
        print("Before Grade 1")
    else: 
        print("Grade ",index)
    
    
    
    
    
    

#define function that count number of letters, words and sentences
def count_letters(text):
    letters = 0
    
    for i in range(0, len(text)):
        if (str.isalpha(text[i])):
            letters += 1
    #print(letters)
    return letters


def count_words(text):
    
    #at the end of the word in the sentence does not have space, then set initial value as '1'.
    words = 1
    
    for i in range(0, len(text)):
        if (ord(text[i]) == 32):
            words += 1
   #print(words)
    return words


def count_sentences(text):
    
    sentences = 0;
    
    for i in range(0, len(text)):
        # 46: '.', 33: '!', 63: '?'  in ascii code
        if (ord(text[i]) == 46 or ord(text[i]) == 33 or ord(text[i]) == 63):
            sentences += 1
    #print(sentences)
    return sentences



if __name__ == "__main__":
    main()
