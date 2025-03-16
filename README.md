# PasswordRater
This Linux Based Program, accompanied with a simple GUI (made with Qt), is designed to give a worst case estimation of the password strength, a user has chosen. The algorithm assumes data leakage of a potential database, as well as information of said leakage being at disposal to a malicious attacker. Algorithm computes the entropy of passwords given certain context. Context being date of birth, name, surname. Usually a realistic algorithm would have to take into account easily available information on social media as well, like friend names, names of each member of close family circle, pet's name and so on. Password entropy is calculated based on multiple factors: does the name/surname of the user appear in the password?, does the password contain birth data?, does the password contain words and if so, how common are they?. Words can be exceptionally easy or hard to guess when trying to brute force a password, depending on the usage frequency. For this project I have decided to utilise a database (GIVE THE PEOPLE CREDIT!!!/Not implemented yet) consisting of each word that happens to be in the English language, accompanied with it's use frequency. Highly used words are sanctioned more, while less used words less(Not implemented yet).  


## Dependencies

Before running the application, you need to install the following Qt5 libraries:

For **Ubuntu/Debian**:

```bash
sudo apt update
sudo apt install qt5-qmake qtbase5-dev qtchooser qtbase5-dev-tools qt5-qmake qt5-qtmultimedia qtbase5-dev qt5-qtmultimedia-dev
```

For **Fedora/RHEL/CentOS**:

```
sudo dnf install qt5-qtbase-devel qt5-qmake qt5-qtmultimedia-devel
```

For Arch Linux:

```
sudo pacman -S qt5-base qt5-tools qt5-multimedia
```


### Building
The application comes prebuilt with the project and available for immediate use after all dependencies have been installed. If a user wants to modify the software, they can later build it using the following method:
```
mkdir example
cd example
cmake ..
make
```

### Testing
Once the project has been built successfuly, the user can navigate to the example folder and start the application using ```./EntropyCalculator```
Enjoy!
