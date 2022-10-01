def isGreater():
    while True:
        try:
            a = input('Enter a number you want to compare')
            b = input('Enter the Comparing Number')
            if a=='q'or b=='q':
                break
            a=int(a)
            b=int(b)
            if a > b:
                print('Greater')
            else:
                print('Smaller')
        except ValueError:
            print('You entered a differnt value which is not an integer')
        except Exception:
            raise print('Kuch To Gadbad hai Daya !!! 🖐️')
        else:
            print('Sab Sahi Chal Raha Hai !!! 👍')
        finally:
            print('Lets have a new try kya khyal hai ? ')
    
isGreater()



