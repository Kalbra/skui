class Skui:
    def __init__(self, elements=[]):
        self.__elements = elements

    def AddButton(self, name, action):
        self.__elements.append({"name": name, "action": action})

    def AddSlider(self, name, from_, to):
        self.__elements.append({"name": name, "from": from_, "to": to})

    def GetString(self):
        return self.__elements

    def PrintToFile(self, path):
        file = open(path, "w")
        file.write(self.__elements)
        file.close()


hello = Skui()

hello.AddButton("fdkl", "df")
hello.AddSlider("skjd", 4, 6)

print(hello.GetString())
