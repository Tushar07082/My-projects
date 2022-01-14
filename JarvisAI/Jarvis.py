
import pyttsx3
import speech_recognition as sr
import datetime


def speak(audio):
        engine.say(audio)
        engine.runAndWait()



def wishMe():
        hour = int(datetime.datetime.now().hour)
        
        if(hour<12):
                speak("Good Morning,Sir")
        
        elif(hour<17):
                speak("Good Afternoon,Sir")
        
        else:
                speak("Good evening,RAKHI")
        
        speak("I am Jarvis, please tell me how may I help you")

def takeCommand():
        r = sr.Recognizer()
        with sr.Microphone() as source:
                print("Listening...")
                r.pause_threshold = 1
                audio = r.listen(source)
        try:
                print("Recognizing...")
                query = r.recognize_google(audio, Language = 'en-in')
                print(f"user said: {query}\n")
        except Exception as e:
                print(e)
                speak("say that again please")
                takeCommand()
        return query

engine = pyttsx3.init('sapi5')
voices = engine.getProperty('voices')
engine.setProperty('voice',voices[1].id)


if __name__=="__main__":
        wishMe();
        takeCommand();
        # speak("I love you Tushar")
        # with open('book.txt','r') as file:
        #         for line in file:
        #                 speak(line)

