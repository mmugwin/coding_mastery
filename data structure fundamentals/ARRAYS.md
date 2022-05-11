# Arrays

## Concepts

- Arrays are fixed size collections of data of the same type. 
  
- Vectors are arrays whose size is dynamic, i.e. it can be changed at will.
  
- Arrays allow random access of data by indexing as opposed to other data structures such as linked lists where data can only be accessed sequentially

Array manipulations include

- **Store**: *variables of the same type in one container*
  
- **Copy**: *make copies of an array for example when we need acces to the elements of the original array after it is manipulated*
  
- **Retrieval**: *for example to get the data stored at a particular location*: ```int num = myArray[5]```. *Alternatively, we neeed to get a specific value, at which point we need to implement search (either for a specific value or for a value that meets a certain criteria)*
  
- **Sorting**: *memorize mergesort and implement it from scratch* ```O(nlog(n))``` *operations*
- **Computing Statistics**: *for example median, mode (frequency), mean etc*

### Example of Array Use Cases

#### Arrays of fixed data

In statistics, the mode of a set of values is the value that appears most often. Write
code that processes an array of survey data, where survey takers have responded to
a question with a number in the range 1–10, to determine the mode of the data set.
For our purpose, if multiple modes exist, any may be chosen.

#### Solution 1: Sort and traverse the array returning the element that occurs most often

Runs in ```O(nlog(n))``` but uses constant space

```c++
int[] findFrequency(int[] surveyData) {
  const int MAX_RESPONSE = 10;
  int histogram[MAX_RESPONSE];

  for(int i = 0; i < MAX_RESPONSE; i++) {
      histogram[i] = 0;
  }

  for(int num : surveryData) {
      histogram[num]++;
  }
  return histogram;
}
```

#### Solution 2: Create an array of frequencies (can use an unordered_map) and return the element with the highest frequency

Runs in ```O(n)``` but also takes ```O(n)``` space to store the hash map. If the range of data is limited as is the case here, then we can consider the space required to be ```O(1)```

```c++

int findMostFrequentElement(int[] surveryData) {
  int mostFrequent;
  int highestFrequency = 0;
  int currentFrequency = 0;
  for (int i = 0; i < ARRAY_SIZE; i++) {
    currentFrequency++;
    // if (surveyData[i] IS LAST OCCURENCE OF A VALUE)
    if (i == ARRAY_SIZE - 1 || surveyData[i] != surveyData[i + 1]) {
      if (currentFrequency > highestFrequency) {
        highestFrequency = currentFrequency;
        mostFrequent = surveyData[i];
      }
      currentFrequency = 0;
    }
  }
}
```

#### Arrays of Data Structures (i.e. Arrays of non-scalar data)

Consider the array of structs below, where each struct is of the form also given below:

Struct 

```c++
  struct student {
    int grade;
    int studentID;
    string name;
  };
```

Array

```c++
const int ARRAY_SIZE = 10;
student studentArray[ARRAY_SIZE] = {
  {87, 10001, "Fred"},
  {28, 10002, "Tom"},
  {100, 10003, "Alistair"},
  {78, 10004, "Sasha"},
  {84, 10005, "Erin"},
  {98, 10006, "Belinda"},
  {75, 10007, "Leslie"},
  {70, 10008, "Candy"},
  {81, 10009, "Aretha"},
  {68, 10010, "Veronica"}
};
```

How can we find the student with the highest score?

```c++
int highest = studentArray[0].grade;
for(int i = 1; i < ARRAY_SIZE; i++) {
    if (studentArray[i].grade > highest) highest = studentArray[i].grade;
}

```

Even better we can find the index of the student with the highest score and then retrive any data about that student:

```c++
int highPosition = 0;
for (int i = 1; i < ARRAY_SIZE; i++) {
  if (studentArray[i].grade > studentArray[highPosition].grade) {
    highPosition = i;
  }
}
```

#### Multidimensional Arrays