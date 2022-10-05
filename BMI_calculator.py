# calculating BMI by taking height and weight as input

print("Please press 1 if you want to give your weight and height in lbs and inches respectively \n   and press 2 if you want to give your weight and height in kgs and cms respectively:", end="  ")
x= int(input())

if x==1:
# calculate in  lb and in:
    print("Please specify your weight:", end=" ")
    weight = float(input())
    print("Please specify your height:", end=" ")
    height = float(input())
    
    bmi = (weight*703)/(height*height)

elif x==2:
#calculate in kgs and cms:

    print("Please input your height in cm:", end=" ")
    height = float(input())
    print("Please input your weight in kgs:", end= " ")
    weight = float(input())

    bmi = (weight*10000)/(height*height)
else: 
    print("Wrong input! Exiting...")
    exit()

print("BMI = ", end="") 
print(bmi)

if bmi<17.5: print("You are Underweight")
elif bmi>=17.5 and bmi<25: print("You are Normal weight")
elif bmi>=25 and bmi<30: print("You are Overweight")
elif bmi>=30 and bmi<35: print("You are Obese (class 1)")
elif bmi>=35 and bmi<40: print("You are Obese (class 2)")
elif bmi>=40: print("You are Obese (class 3)")