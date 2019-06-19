import matplotlib.pyplot as plt

OpenTheFile=open("coordinates.txt","r")
All=OpenTheFile.readlines()
OpenTheFile.close()
All2=[]
for i in range(len(All)):
    All[i]=All[i].replace("\n","")
    if(All[i]==""):
        pass
    elif(All[i][0]=="x"):
        pass
    else:
        All2.append(All[i])



XCoordinates=[int((All2[i].split("\t\t"))[0]) for i in range(len(All2))]
YBestCoordinates=[float((All2[i].split("\t\t"))[1]) for i in range(len(All2))]
YAverageCoordinates=[float((All2[i].split("\t\t"))[2]) for i in range(len(All2))]


plt.plot(XCoordinates, YBestCoordinates, 'r')
#plt.plot(XCoordinates, YAverageCoordinates, 'g')

plt.axis([0, (XCoordinates[-1]+1), 0,(YBestCoordinates[0]+1)])
#plt.axis([0, (XCoordinates[-1]+1), 0,(YAverageCoordinates[0]+1)])

plt.show()
