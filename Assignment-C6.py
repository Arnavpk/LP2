# Assignment-C6 (Expert System - Hospitals and Medical Facilities)

"""
THIS CODE HAS BEEN TESTED AND IS FULLY OPERATIONAL.

Problem Statement: Implement any one of the following Expert System
  II. Hospitals and medical facilities

Code from ArtificialIntelligence (SPPU - Third Year - Computer Engineering - Content) repository on KSKA Git: https://git.kska.io/sppu-te-comp-content/ArtificialIntelligence
"""

# BEGINNING OF CODE
def knowledge():
    return {
        "sneezes":"Cold",
        "temperature":"Fever",
        "weakness": "Iron Deficiency",
        "forgets":"Alzeimers",
        "cough":"Covid-19",
        "paleness":"Flu"
    }

def ask(q):
    while True:
        a= input(f"{q} [Yes/No]\t").lower()
        if a in ['yes', 'no']:
            if a== "yes": return True
            return False
        else: print("Please Answer in Yes or No.\n")

def questions_List():
    return {
        "sneezes": "Are you sneezing frequently?",
        "temperature": "Do you have high temperature?",
        "weakness": "Are you feeling weak in your legs and arms?",
        "forgets": "Are you able to remember things clearly?",
        "cough": "Do you have cough or sore throat?",
        "paleness": "Does your skin look pale?",
    }

# P.S. The author wants the user to notice the subtle use of questions.items() to retrieve the entire key value pair from the dictionary.

def doctor():
    print("*"*30,"\nWelcome to Doctor Smith's!","*"*30)
    know=knowledge()
    questions=questions_List()
    symtoms={}
    for s,q in questions.items():
        symtoms[s]=ask(q)
    diagnosis=[]
    for sym in know:
        if symtoms[sym]:
            diagnosis.append(know[sym])
    print("\n\nYour Diagnosis is: \n")
    for d in diagnosis:
        print(d)

doctor()
# END OF CODE
