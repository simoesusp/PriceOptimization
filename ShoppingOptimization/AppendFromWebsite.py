def GeneralListFunction(websiteurl):
    import urllib.request
    from urllib.request import Request, urlopen
    from re import findall
    from re import DOTALL
    from re import search
    from re import escape
    import os
    ###################################################################################################
    restricted=['JOKER GAMES','Fire Ice Card Games']
    f=open("towriti.txt","r")
    snlca=f.readlines()
    f.close
    snlca=[i.replace("\n","") for i in snlca]
    ###################################################################################################
    #webpage=input("Insira abaixo o endereço virtual do seu deck no site 'Ligamagic'\n")
    req = Request(websiteurl, headers={'User-Agent': 'Mozilla/5.0'})
    page = urlopen(req).read().decode('utf-8')
    ###################################################################################################

    Cards=list(set(findall(r"""class='deck-qty'>([1-9][0-9]*?)&.*?&card=(.*?)">""",page)))
    Cards=[list(i) for i in Cards]

    todel=[]
    for i in range(len(Cards)):
        if((Cards[i][1] == "Island") or (Cards[i][1] == "Swamp") or (Cards[i][1] == "Mountain") or (Cards[i][1] == "Plains") or (Cards[i][1] == "Forest")):
            j=i-len(todel)
            todel.append(j)
        else:
            pass

    for i in range(len(todel)):
        del Cards[todel[i]]
    ###################################################################################################

    GeneralList=[[],[],[]]

    for i in range(len(Cards)):
        print(str(i)+"/"+str(len(Cards))+":"+Cards[i][1]+"\n")
        #print("\n"+str(i+1)+"/"+str(len(Cards))+"\n\n")
        virtualcardname=Cards[i][1].replace(" ","%20")
        cardwebsite="https://www.ligamagic.com.br/?view=cards/card&card="+virtualcardname
        req2 = Request(cardwebsite, headers={'User-Agent': 'Mozilla/5.0'})
        actualpage = urlopen(req2).read().decode('utf-8')
        numberofthesite=r"""(?<=value=')[0-9]+(?='></div>.*?<div id='card-menu'>.*?<a href="[.]/[?]view=cards/card&card=)"""
        numberofthesite=search(numberofthesite,actualpage,DOTALL).group(0)
        
        sitenames= list(set(findall(r"""(?<=><img title=").+?(?=" src='//www.lmcorp.com.br)""", actualpage)))

        for j in range(len(sitenames)):
            print("\t"+str(j+1)+"/"+str(len(sitenames))+"\n")
            namey=sitenames[j]
            '''
            if(namey in restricted):
                pass
            elif(not(namey in snlca)):
                print("Card: "+Cards[i][1]+"/ Site: "+namey+"\n")
                rest=int(input("restricted?[0/1] "))
                if(rest):
                    restricted.append(namey)
                else:
                    snlca.append('')                    
                    snlca.append('')                    
                    snlca.append(namey)                    
                    siti=input('site url till and including (&card=): ')
                    snlca.append(siti)
                    shipi=input('shipping: ')                    
                    snlca.append(shipi)
                    snlca.append('##############################################################################')
                    f=open("towriti.txt","w")
                    f.close()
                    f=open("towriti.txt","a+")
                    for df in snlca:
                        f.write(df+"\n")
                    f.close()
            '''
            if(not(namey in restricted)):
                #if(0):

                if namey in GeneralList[0]:
                    pass
                else:
                    GeneralList[0].append(namey)
                    araysss=[[1000000 for n in range(int(Cards[o][0]))] for o in range(len(Cards))]
                    GeneralList[1].append(araysss)
        ###################################################################################################
                cposition=snlca.index(namey)
                correctsite=snlca[cposition+1]+numberofthesite+snlca[cposition+2]
                req3 = Request(correctsite, headers={'User-Agent': 'Mozilla/5.0'})
                correctsitetext = urlopen(req3).read().decode('utf-8')

        ###################################################################################################
                disorderedquantityandprice1=findall(r"""(?<=<td class='hmin30 )[brdt]*?'>[0-9]+? unid[.]</td>\s*?<td class='itemPreco hmin30 [brdt]*?'>R[$] [0-9]+?,[0-9]*?(?=</td>)""",correctsitetext,DOTALL)
                disorderedquantityandprice2=findall(r"""(?<=<td class='hmin30 )[brdt]*?'>[0-9]+? unid[.]</td>\s*?<td class='itemPreco hmin30 [brdt]*?' title='.*?<font color='.*?' style='.*?'>R[$] [0-9]+?,[0-9]*?</font>""",correctsitetext,DOTALL)
                disorderedquantityandprice3=findall(r"""(?<=<span class="product-price)">[0-9]+? unid[.]</span>\s*?</div>\s*?<div class=".*?<span class="product-price">R[$] [0-9]+?,[0-9]*?(?=</span>)""",correctsitetext,DOTALL)
                disorderedquantityandprice4=findall(r"""(?<=<span class="product-price)">[0-9]+? unid[.]</span>\s*?</div>\s*?<div class=".*?<span class="product-price">.*?<br/><font color='red'>R[$] [0-9]+?,[0-9]*?(?=</font>)""",correctsitetext,DOTALL)
                provisory=[]
        #################################################
                for k1 in range(len(disorderedquantityandprice1)):
                    multiplier=int(search(r"""(?<='>)[0-9]*?(?= unid)""",disorderedquantityandprice1[k1]).group(0))
                    value=((search(r"""(?<=R[$] )[0-9]*?,[0-9]*""",disorderedquantityandprice1[k1])).group(0)).replace(",",".")
                    if(multiplier):
                        for l in range(multiplier):
                            provisory.append(value)
                            
                    else:
                        pass
        #################################################
                for k2 in range(len(disorderedquantityandprice2)):
                    multiplier2=int(search(r"""(?<='>)[0-9]*?(?= unid)""",disorderedquantityandprice2[k2]).group(0))
                    value2=((search(r"""(?<=R[$] )[0-9]*?,[0-9]*(?=</font>)""",disorderedquantityandprice2[k2])).group(0)).replace(",",".")
                    if(multiplier2):
                        for l in range(multiplier2):
                            provisory.append(value2)
                            
                    else:
                        pass
        #################################################
                for k3 in range(len(disorderedquantityandprice3)):
                    multiplier=int(search(r"""(?<=">)[0-9]*?(?= unid)""",disorderedquantityandprice3[k3]).group(0))
                    value=((search(r"""(?<=">R[$] )[0-9]*?,[0-9]*""",disorderedquantityandprice3[k3])).group(0)).replace(",",".")
                    if(multiplier):
                        for l in range(multiplier):
                            provisory.append(value)
                            
                    else:
                        pass

        #################################################
                for k4 in range(len(disorderedquantityandprice4)):
                    multiplier=int(search(r"""(?<=">)[0-9]*?(?= unid)""",disorderedquantityandprice4[k4]).group(0))
                    value=((search(r"""(?<=<font color='red'>R[$] )[0-9]*?,[0-9]*""",disorderedquantityandprice4[k4])).group(0)).replace(",",".")
                    if(multiplier):
                        for l in range(multiplier):
                            provisory.append(value)
                            
                    else:
                        pass

        ##########################################################################                
                provisory= sorted(provisory)
                
                if(len(provisory)<int(Cards[i][0])):
                    for s in range((int(Cards[i][0])-len(provisory))):
                        provisory.append(1000000)

                indexiii=GeneralList[0].index(namey)
                for n in range(len(GeneralList[1][indexiii][i])):
                    GeneralList[1][indexiii][i][n]=float(provisory[n])
            else:
                pass

    for i in range(len(GeneralList[0])):
        shippposition=snlca.index(GeneralList[0][i])
        GeneralList[2].append(snlca[shippposition+3])
    ###################################################################################################
    ###################################################################################################

    createsummary=open("summary.txt","w")
    createsummary.close()
    appendsummary=open("summary.txt","a+")

    numb=0

    Cardsfull=0

    for i in range(len(Cards)):
        Cardsfull+=int(Cards[i][0])

    appendsummary.write("number of sites\t\tnumber of types of cards\t\ttotal number of cards\n"+str(len(GeneralList[0]))+"\n"+str(len(Cards))+"\n"+str(Cardsfull)+"\n")
    for i in range(len(Cards)):
        for j in range(int(Cards[i][0])):
            numb+=1
            numbi=f"{numb:03d}"
            appendsummary.write((numbi+":"+Cards[i][1])+"\t")
    
    appendsummary.write("\n")
    numb=0

    for i in range(len(GeneralList[0])):
        numb+=1
        numbi=f"{numb:03d}"
        appendsummary.write((numbi+":"+GeneralList[0][i])+"\t")
        
    appendsummary.write("\n&")

    for i in range(len(GeneralList[0])):
        for j in range(len(Cards)):
            appendsummary.write("\n"+str(123456780+int(Cards[j][0])))
            for k in range(int(Cards[j][0])):
                toput="\n"+str(GeneralList[1][i][j][k])
                appendsummary.write(toput)
        if("**" in GeneralList[2][i]):
            part1=(GeneralList[2][i]).replace("*","")
            part2="1.05"
        elif("*" in GeneralList[2][i]):
            part1=(GeneralList[2][i]).replace("*","")
            part2="1.02"
        else:
            part1=GeneralList[2][i]
            part2="1.00"
        toappshipp=("\n"+str(123456782)+"\n"+part1+"\n"+part2)
        appendsummary.write(toappshipp)
    appendsummary.close()
    ###################################################################################################
    ###################################################################################################
    ###################################################################################################
    os.system('xdg-open summary.txt')



webpage=input("Insira abaixo o endereço virtual do seu deck no site 'Ligamagic'\n")

All=(GeneralListFunction(webpage))