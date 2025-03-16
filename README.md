# PasswordRater Rentropy

PasswordRater is a Linux-based application equipped with a user-friendly graphical interface (developed using Qt) designed to provide an in-depth evaluation of password strength. The program offers an estimation of password security under a worst-case scenario, assuming the potential compromise of a database and access to sensitive information by a malicious actor. The algorithm calculates the entropy of a password by considering various contextual factors, including personal data such as the user's name, surname, and date of birth.

Typically, a realistic password strength algorithm would also take into account publicly accessible information, such as details available on social media platforms—names of family members, friends, pets, and other personal identifiers. Password entropy is evaluated based on several criteria, including the presence of personal information (e.g., name or surname), the use of birth-related data, and the occurrence of common words.

The strength of words is assessed based on their frequency of usage. Words with high frequency are considered easier to guess and thus are penalized more heavily in the password strength calculation, while less common words are given less weight. To enhance the accuracy of this assessment, the program will integrate a word frequency database sourced from Kaggle's English Word Frequency Dataset (integration pending), which includes a comprehensive list of English words along with their respective usage frequencies. This will enable a more refined evaluation, with commonly used words being more heavily penalized compared to rare ones.

In summary, PasswordRater provides a robust mechanism for determining password strength by considering a wide range of factors that contribute to the potential vulnerability of passwords, offering a thorough security analysis based on realistic, real-world data.

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
