import time

print("Welcom to atm machine: ")

def ATM():
    print("Select Language: \n1. English \n2. Marathi \n3. Hindi")
    language = int(input("Enter your choice: "))
    match language:
        case 1:
            print("Select Operation: \n1. Check Balance \n2. Withdraw cash \n3. Set Pin")
            operation = int(input("Enter your choice: "))
            match operation:
                case 1:
                    pin = input("Enter your PIN: ")
                    if pin == "":
                        print("Invalid PIN")
                        return
                    print("Your Balance is 9000")
                case 2:
                    pin = input("Enter your PIN: ")
                    if pin == "":
                        print("Invalid PIN")
                        return
                    print("Select Account Type: \n1. Saving Account \n2. Current Account")
                    acc = int(input("Enter your choice: "))
                    if acc not in (1, 2):
                        print("Inavlid choice!")
                        return
                    amount = int(input("Enter amount: "))
                    if amount < 100:
                        print("Amount must greater than 100!")
                        return
                    print("Please wait processing your transaction...")
                    time.sleep(3)
                    print("Take your card...")
                    time.sleep(2)
                    print("Take cash..")
                    time.sleep(2)
                    print("Transaction Completed")
                case 3:
                    newPin = input("Enter a new PIN: ")
                    confirmPin = input("Confirm your PIN: ")
                    if newPin == "" or confirmPin == "":
                        print("PIN is empty")
                        return
                    print("PIN set Successfully" if int(newPin) == int(confirmPin) else "PIN not match")
        case 2:
            print("कृपया ऑपरेशन निवडा: \n1. शिल्लक तपासा \n2. रोख पैसे काढा \n3. पिन सेट करा")
            operation = int(input("आपला पर्याय प्रविष्ट करा: "))
            match operation:
                case 1:
                    pin = input("आपला पिन प्रविष्ट करा: ")
                    if pin == "":
                        print("अवैध पिन")
                        return
                    print("आपली शिल्लक 9000 आहे")
                case 2:
                    pin = input("आपला पिन प्रविष्ट करा: ")
                    if pin == "":
                        print("अवैध पिन")
                        return
                    print("खाते प्रकार निवडा: \n1. बचत खाते \n2. चालू खाते")
                    acc = int(input("आपला पर्याय प्रविष्ट करा: "))
                    if acc not in (1, 2):
                        print("अवैध निवड!")
                        return
                    amount = int(input("रक्कम प्रविष्ट करा: "))
                    if amount < 100:
                        print("रक्कम 100 पेक्षा जास्त असावी!")
                        return
                    print("कृपया प्रतीक्षा करा, आपला व्यवहार प्रक्रिया होत आहे...")
                    time.sleep(3)
                    print("आपले कार्ड घ्या...")
                    time.sleep(2)
                    print("रोख रक्कम घ्या..")
                    time.sleep(2)
                    print("व्यवहार पूर्ण झाला")
                case 3:
                    newPin = input("नवीन पिन प्रविष्ट करा: ")
                    confirmPin = input("आपला पिन पुन्हा प्रविष्ट करा: ")
                    if newPin == "" or confirmPin == "":
                        print("पिन रिकामा आहे")
                        return
                    print("पिन यशस्वीरीत्या सेट केला" if int(newPin) == int(confirmPin) else "पिन जुळत नाही")
        case 3:
            print("कृपया ऑपरेशन चुनें: \n1. बैलेंस चेक करें \n2. नकद निकासी \n3. पिन सेट करें")
            operation = int(input("अपना विकल्प दर्ज करें: "))
            match operation:
                case 1:
                    pin = input("अपना पिन दर्ज करें: ")
                    if pin == "":
                        print("अमान्य पिन")
                        return
                    print("आपका बैलेंस 9000 है")
                case 2:
                    pin = input("अपना पिन दर्ज करें: ")
                    if pin == "":
                        print("अमान्य पिन")
                        return
                    print("खाता प्रकार चुनें: \n1. बचत खाता \n2. चालू खाता")
                    acc = int(input("अपना विकल्प दर्ज करें: "))
                    if acc not in (1, 2):
                        print("अमान्य विकल्प!")
                        return
                    amount = int(input("राशि दर्ज करें: "))
                    if amount < 100:
                        print("राशि 100 से अधिक होनी चाहिए!")
                        return
                    print("कृपया प्रतीक्षा करें, आपका लेनदेन प्रोसेस हो रहा है...")
                    time.sleep(3)
                    print("अपना कार्ड लें...")
                    time.sleep(2)
                    print("नकद लें..")
                    time.sleep(2)
                    print("लेनदेन पूर्ण हुआ")
                case 3:
                    newPin = input("नया पिन दर्ज करें: ")
                    confirmPin = input("पिन की पुष्टि करें: ")
                    if newPin == "" or confirmPin == "":
                        print("पिन खाली है")
                        return
                    print("पिन सफलतापूर्वक सेट किया गया" if int(newPin)==int(confirmPin) else "पिन मेल नहीं खा रहा")

ATM()
