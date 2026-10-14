# earlpfau.github.io

## Professional Self-Assessment

## Enhancement Project
The following is the project from my CS499 - Computer Science Capstone, with Southern New Hampshire University.

## What is the project?
The project is to enhance three artifacts from previouse course work or from other personal projects.
I choose the same project for my artifacts to enhance.
The categories for this enhancement project is:
- Software Design and Engineering
- Algorithms and Data Structures
- Databases

## The Artifact
My artifact is my Investment Calculator Application from the course CS210 - Programming Languages, back from February 2025 - which is a console app written in C++.
The reason I chose to enhance this entire project rather than enhancing multiple projects is because this was one of my first C++ programs that I felt could be enhanced in all three categories. 

## Enhancements
- To start this project off I did a self-code review of the potential artifacts within my Investment Calculator Application, which is in the form of a short video.
-  Then I moved into enahnacement one - Software Design and Engineering.
- Then I moved on to enhancement two - Algorithms and Data Structures. (Completed, but waiting on feedback.)
- Then for the final enhancement three - Databases. (Started, but not complete.)

## Self-Code Review
<span><ins><strong>Code Review Video</strong></ins></span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
<span><ins><strong>Code Review Checklist</strong></ins></span>

Click on the video or use this link https://youtu.be/rqeax5MER7k

[![Watch the video](https://img.youtube.com/vi/rqeax5MER7k/0.jpg)](https://youtu.be/rqeax5MER7k) <a href="Docs/cs499_code_review_checklist.pdf"> 
  <img src="Docs/CodeReviewChecklist.png" width="300">


## Enhancement One: Software Design and Engineering

### Artifact: [name of artifacts]

### Original Files
[Original InputOutput.cpp](Enhancement%20One%20Artifact%20Pfau/Original%20files/InputOutput.cpp)

[Original InputOutput.h](Enhancement%20One%20Artifact%20Pfau/Original%20files/InputOutput.h)

### Enhanced Files
[Enhanced InputOutput.cpp](Enhancement%20One%20Artifact%20Pfau/Enhancement%20One%20Files/InputOutput.cpp)

[Enhanced InputOutput.h](Enhancement%20One%20Artifact%20Pfau/Enhancement%20One%20Files/InputOutput.h)

### Plan:
[Enhancement One Narrative.pdf](Docs/Enhancement%201%20Narrative%20Pfau.pdf)

Justification for artifact inclusion:

Why did you select this item? What specific components of the artifact showcase your skills and abilities in software development? How was the artifact improved?

I selected this artifact because it was one of my first C++ projects and I definitely did not have strong skills in software engineering and design. There were a few areas where I did not make it clear enough to the user on what was expected or even what the program did. The components of my artifact that showcase my skills and abilities in software development is how the program itself flows, with clear instructions and intent given to the user.I felt that I was assuming the user knows what the program wants from them in terms of user input.

I improved this artifact by adding an additional method called printWelcomeScreen(), which just prints a small welcome message to the screen with a small description on what the program does. I also went through all the methods within this artifact and made it clear in the output statements what is acceptable input for each variable. I also cleaned up some inline comments and put a header comment along with comment blocks above each method. 

Course Outcomes met:

Did you meet the course outcomes you planned to meet with this enhancement in Module One? Do you have any updates to your outcome-coverage plans?
I felt that I have met the course outcomes that I planned to meet with this enhancement, which are:
•	Employ strategies for building collaborative environments that enable diverse audiences to support organizational decision making in the field of computer science.
•	Design, develop, and deliver professional-quality oral, written, and visual communications that are coherent, technically sound, and appropriately adapted to specific audiences and contexts.
•	Demonstrate an ability to use well-founded and innovative techniques, skills, and tools in computing practices for the purpose of implementing computer solutions that deliver value and accomplish industry-specific goals.

Reflection:

What did you learn as you were creating it and improving it? What challenges did you face?
Looking back on my process of enhancing and modifying this artifact, I learned through discovery that there was by far more user clarification than I first suspected. Once I got into the groove of enhancing and testing, I found that there could possibly be more user confusion in how the format for input was expected. I then discovered that the Investment Calculator application was not protected from users entering extreme values, for example when the user is asked for the length in years that they want to calculate the compounding interest, they were able to input how ever many years that they want. This could not only break the application or cause unintended consequences or outcomes, due to the possibility of inputting some extremely large value like 100,000 years. This is planned to be fixed with enhancement two, because it has to do with algorithms and data structures. I have a tendency to do a thing called feature creep, which is where I do more than what is required in terms of coding. This could be a bad thing when working in teams where we all have our predefined requirements, by adding additional features could break or cause confusion.
The biggest challenge that I faced during the first enhancement was deciding on how I should go about modifying and enhancing the design, there is always more than one way to do something. I decided to stick with the least complex fix, which should allow for easy modification/updating in the future. The next challenge that I faced and continue to face with all my projects is in how I write my comment blocks above each code block. I tend to explain what each line does rather than what the block of code does as a whole. 
To overcome these challenges, I keep a sticky note attached to my computer monitor with the words: “feature creep”, and “comments = what it does as a block of code“. I do understand that sometimes inline comments are needed but only to explain a line of code that is not clear or that is unusual.


### Reality:

### My Thoughts:



## Enhancement Two: Algorithms and Data Structures

### Artifact: [name of artifacts]

### Original Files
[Original AllCalculations.cpp](Enhancement%20Two%20Artifact%20Pfau/Original%20Files/AllCalculations.cpp)

[Original AllCalculations.h](Enhancement%20Two%20Artifact%20Pfau/Original%20Files/AllCalculations.h)

[Original InputOutput.cpp](Enhancement%20Two%20Artifact%20Pfau/Original%20Files/InputOutput.cpp)

[Original InputOutput.h](Enhancement%20Two%20Artifact%20Pfau/Original%20Files/InputOutput.h)

### Enhanced Files
[Enhanced AllCalculations.cpp](Enhancement%20Two%20Artifact%20Pfau/Enhancement%20Two%20Files/AllCalculations.cpp)

[Enhanced AllCalculations.h](Enhancement%20Two%20Artifact%20Pfau/Enhancement%20Two%20Files/AllCalculations.h)

[Enhanced InputOutput.cpp](Enhancement%20Two%20Artifact%20Pfau/Enhancement%20Two%20Files/InputOutput.cpp)

[Enhanced InputOutput.h](Enhancement%20Two%20Artifact%20Pfau/Enhancement%20Two%20Files/InputOutput.h)

### Plan:
[Enhancement Two Narrative.pdf](Docs/Enhancement%202%20Narrative%20Pfau.pdf)

Justification for artifact inclusion:

Why did you select this item? What specific components of the artifact showcase your skills and abilities in algorithms and data structure? How was the artifact improved?
I selected the AllCalculations.cpp as my artifact for my second enhancement because it had some issues with how I was calculating the compounding interest with monthly deposits. The specific components of this artifact showcase showcases my skills and abilities in algorithms and data structures through how I enhanced my original two algorithms to be more efficient in the way it calculates the compounding interest for each year.
I improved the algorithm by moving the calculations for monthly rate to the outside as more of a constant declared as a variable monthlyRate, which I was originally calculating it through each loop, which was unnecessary. 
I also selected the InputOutput.cpp again, because I needed to add a condition to the methods getInitialInfo() and menuSelection(). The enhancement came in the form of a condition for the amount of years so the user can’t go over 100 years. Without this condition the user could type in any length of time in years and could cause the program to continue to run without stopping. 
I also took those same two methods and pulled the blocks of code that gathered the information from the use and created four more methods called getUserInvestmentAmount(), getUserMonthlyDeposit(), getUserInterestRate(), and getUserNumberYears(). This I never caught in my first enhancement and in my self-code review. The program used to have the same blocks of code in two different areas and now they just call them instead. 
I went through both files and removed unessasary inline comments and created comment blocks where needed. I also added headers to the top explaining the overall what the file does. I discovered an accident through reading an article on C++, where I was causing unnecessary flushes to the streams buffer by inserting new lines through ‘endl’, which I should have been using ‘\n’ instead.
I also found unused variables in the AllCalculations.h file that I first thought I was using and discovered that I never once used them, the m_yearIndex, m_balance, m_interestEarnedThisYear.


Course Outcomes met:

Did you meet the course outcomes you planned to meet with this enhancement in Module One? Do you have any updates to your outcome-coverage plans?
I did meet the course outcomes that I planned to meet with this enhancement. I don’t have any updates to my outcome-coverage plans. 

Reflection:

What did you learn as you were creating it and improving it? What challenges did you face?
As I went through the process of enhancing and modifying the artifact, I discovered something that I missed in my self-code review. I found that I was recreating the same blocks of code twice and for the same purpose but was using them in different areas. I made those blocks of code their own methods within the InputOutput.cpp file and just called them into the other methods that needed them. I discovered this during my testing phase where I made changes to conditions for user input and was still able to input what I was attempting to prevent. 
The main challenges that I faced was having to adjust my design from what I initially did in my enhancement one, without completely making the previous work pointless. I feel that I kept those enhancements from enhancement one intact but with some slight modifications the how and when.


### Reality:

### My Thoughts:



## Enhancement Three: Databases

### Artifact: [name of artifacts]

### Original Files
[Original InputOutput.cpp](Enhancement%20Three%20Artifact%20Pfau/Original%20Files/InputOutput.cpp)

[Original InputOutput.h](Enhancement%20Three%20Artifact%20Pfau/Original%20Files/InputOutput.h)

[Original main.cpp](Enhancement%20Three%20Artifact%20Pfau/Original%20Files/main.cpp)

### Enhanced Files
[Enhanced InputOutput.cpp](Enhancement%20Three%20Artifact%20Pfau/Enhancement%20Three%20Files/InputOutput.cpp)

[Enhanced InputOutput.h](Enhancement%20Three%20Artifact%20Pfau/Enhancement%20Three%20Files/InputOutput.h)

[Enhanced UserDatabase.cpp](Enhancement%20Three%20Artifact%20Pfau/Enhancement%20Three%20Files/UserDatabase.cpp)

[Enhanced UserDatabase.h](Enhancement%20Three%20Artifact%20Pfau/Enhancement%20Three%20Files/UserDatabase.h)

[Enhanced main.cpp](Enhancement%20Three%20Artifact%20Pfau/Enhancement%20Three%20Files/main.cpp)

### Outside Supporting Files:
This header file comes from [put the author and link to the authors github page here]

[Supporting json.hpp](Enhancement%20Three%20Artifact%20Pfau/Outside%20Supporting%20Files/json.hpp)

### Plan:
[Enhancement Three Narrative.pdf](Docs/Enhancement%203%20Narrative%20Pfau.pdf)

Justification for artifact inclusion:

Why did you select this item? What specific components of the artifact showcase your skills and abilities in software development? How was the artifact improved?
The main reason that I included these as my artifact for my ePortfolio is because there was no database for this application and I felt that it needed a simple and local way of storing user data so users can reload their own investment information if they want to come back and mess with the different attributes. 

This will show my ability to successfully incorporate community made libraries and use them inside existing programs. This requires reading documentation from the developer and being able to problem solve issues that arise.

The specific components that will showcase my skills and abilities in software development is how and what I used to add a database to my C++ application. I decided to use Json as my database, which is not natively supported as a database type for C++. I found a library and project on GitHub which makes it possible to add Json support in C++. It’s called JSON for Modern C++ by Niels Lohmann which can be found here: https://github.com/nlohmann/json 

Course Outcomes met:

Did you meet the course outcomes you planned to meet with this enhancement in Module One? Do you have any updates to your outcome-coverage plans?
I did meet the course outcomes that I planned to meet with this enhancement. 
I do have an update but in the sense that I feel that this enhancement alone is meeting all course outcomes in one way or another. I have to redesign what I have already done in my first enhancement in order to successfully incorporate Json into the application. This also meets what was needed in the enhancement two as well, with having to change algorithms and data structures in order to incorporate the Json database and save and load user data. 

Reflection:

What did you learn as you were creating it and improving it? What challenges did you face?
I felt extremely confident at first when starting the process of enhancing and modifying this artifact. I quickly found out that chasing down issues with saving and loading user data was like going down a rabbit hole. I at first figured I could just wing it and quickly add this database feature with no issues. After feeling like I made more of a mess of the code and running into a slight bit of confusion, I went back to the drawing board and back to the basics of computer science. Looked through what I had already and focused on writing tons of comments throughout my files to help facilitate me keeping on track and not jumping around. I discovered nearly a year ago that I do this thing called feature-creep where I tend to add additional things before I even need them which causing unforeseen issues and bugs when I test the program. I stick with one feature and if I want to add something I turn it into a comment, so I don’t forget. 


### Reality:

### My Thoughts:


