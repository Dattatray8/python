import time

print("Welcom to atm machine: ")

def ATM():
    print("Select Language: ")
    print("1. English")
    print("2. Marathi")
    print("3. Hindi")
    language = int(input("Enter your choice: "))
    match language:
        case 1:
            print("Select Operation: ")
            print("1. Check Balance")
            print("2. Withdraw cash")
            print("3. Set Pin")
            operation = int(input("Enter your choice: "))
            match operation:
                case 1:
                    pin = input("Enter your PIN: ")
                    if pin == "":
                        print("Invalid PIN")
                        return
                    else:
                        print("Your balance is 9000")
                case 2:
                    pin = input("Enter your PIN: ")
                    if pin == "":
                        print("Invalid PIN")
                        return
                    print("Select Account Type: ")
                    print("1. Saving Account")
                    print("2. Current Account")
                    acc = int(input("Enter your choice: "))
                    if acc == 1 or acc == 2:
                        amount = int(input("Enter amount: "))
                        if amount > 100:
                            print("Please wait processing your transaction...")
                            time.sleep(3)
                            print("Take your card...")
                            time.sleep(2)
                            print("Take cash..")
                            time.sleep(2)
                            print("Transaction Completed")
                        else:
                            print("Amount must greater than 100!")
                            return
                    else:
                        print("Inavlid choice!")
                        return
                case 3:
                    newPin = input("Enter a new PIN: ")
                    confirmPin = input("Confirm your PIN: ")
                    if newPin == "" or confirmPin == "":
                        print("PIN is empty")
                        return
                    if int(newPin) == int(confirmPin):
                        print("PIN set Successfully")
                    else:
                        print("PIN not match")
                        return
        case 2:
            print("कृपया ऑपरेशन निवडा: ")
            print("1. शिल्लक तपासा")
            print("2. रोख पैसे काढा")
            print("3. पिन सेट करा")
            operation = int(input("आपला पर्याय प्रविष्ट करा: "))
            match operation:
                case 1:
                    pin = input("आपला पिन प्रविष्ट करा: ")
                    if pin == "":
                        print("अवैध पिन")
                        return
                    else:
                        print("आपली शिल्लक 9000 आहे")
                case 2:
                    pin = input("आपला पिन प्रविष्ट करा: ")
                    if pin == "":
                        print("अवैध पिन")
                        return
                    print("खाते प्रकार निवडा: ")
                    print("1. बचत खाते")
                    print("2. चालू खाते")
                    acc = int(input("आपला पर्याय प्रविष्ट करा: "))
                    if acc == 1 or acc == 2:
                        amount = int(input("रक्कम प्रविष्ट करा: "))
                        if amount > 100:
                            print("कृपया प्रतीक्षा करा, आपला व्यवहार प्रक्रिया होत आहे...")
                            time.sleep(3)
                            print("आपले कार्ड घ्या...")
                            time.sleep(2)
                            print("रोख रक्कम घ्या..")
                            time.sleep(2)
                            print("व्यवहार पूर्ण झाला")
                        else:
                            print("रक्कम 100 पेक्षा जास्त असावी!")
                            return
                    else:
                        print("अवैध निवड!")
                        return
                case 3:
                    newPin = input("नवीन पिन प्रविष्ट करा: ")
                    confirmPin = input("आपला पिन पुन्हा प्रविष्ट करा: ")
                    if newPin == "" or confirmPin == "":
                        print("पिन रिकामा आहे")
                        return
                    if int(newPin) == int(confirmPin):
                        print("पिन यशस्वीरीत्या सेट केला")
                    else:
                        print("पिन जुळत नाही")
                        return
        case 3:
            print("कृपया ऑपरेशन चुनें: ")
            print("1. बैलेंस चेक करें")
            print("2. नकद निकासी")
            print("3. पिन सेट करें")
            operation = int(input("अपना विकल्प दर्ज करें: "))
            match operation:
                case 1:
                    pin = input("अपना पिन दर्ज करें: ")
                    if pin == "":
                        print("अमान्य पिन")
                        return
                    else:
                        print("आपका बैलेंस 9000 है")
                case 2:
                    pin = input("अपना पिन दर्ज करें: ")
                    if pin == "":
                        print("अमान्य पिन")
                        return
                    print("खाता प्रकार चुनें: ")
                    print("1. बचत खाता")
                    print("2. चालू खाता")
                    acc = int(input("अपना विकल्प दर्ज करें: "))
                    if acc == 1 or acc == 2:
                        amount = int(input("राशि दर्ज करें: "))
                        if amount > 100:
                            print("कृपया प्रतीक्षा करें, आपका लेनदेन प्रोसेस हो रहा है...")
                            time.sleep(3)
                            print("अपना कार्ड लें...")
                            time.sleep(2)
                            print("नकद लें..")
                            time.sleep(2)
                            print("लेनदेन पूर्ण हुआ")
                        else:
                            print("राशि 100 से अधिक होनी चाहिए!")
                            return
                    else:
                        print("अमान्य विकल्प!")
                        return
                case 3:
                    newPin = input("नया पिन दर्ज करें: ")
                    confirmPin = input("पिन की पुष्टि करें: ")
                    if newPin == "" or confirmPin == "":
                        print("पिन खाली है")
                        return
                    if int(newPin) == int(confirmPin):
                        print("पिन सफलतापूर्वक सेट किया गया")
                    else:
                        print("पिन मेल नहीं खा रहा")
                        return

ATM()