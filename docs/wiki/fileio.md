# Fileio

#### Links:

[Home](https://github.com) | [Link1][1] | [Link2][2] | [Link3][3] | [Link4][4] | [Link5][5] |   
---- | ----- | ----- | ----- | ----- | ----- |

#### Include location: `src/fileio/fileio.h`

### SaveString

```cpp
void SaveString(QString path, QString data);
```

#### Description:
Saves a qstring to a file. You have to refer the filepath and the data to save.

--------

### LoadString

```cpp
QString LoadString(QString path);
```

#### Description:
Loads a string from file. You have to refer the path. The data is returned.

--------

### SaveJsonDocument

```cpp
void SaveJsonDocument(QString path, QJsonDocument document);
```

#### Description:
Saves a qjsondocument to a file. You have to refer the filepath and the qjsondocument to save.

--------

### LoadJsonDocument

```cpp
QJsonDocument LoadJsonDocument(QString path);
```

#### Description:
Loads a qjsondocument from file. You have to refer the path. The qjsondocument is returned.





[1]: http://slashdot.org
[2]: http://slashdot.org
[3]: http://slashdot.org
[4]: http://slashdot.org
[5]: http://slashdot.org
