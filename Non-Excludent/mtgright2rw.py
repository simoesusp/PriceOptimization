def GeneralListFunction(websiteurl):
    import urllib.request
    from urllib.request import Request, urlopen
    from re import findall
    from re import DOTALL
    from re import search
    from re import escape
    import os
    ###################################################################################################
    snlca=['', '', '', 'Card Castle', 'https://www.cardcastle.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '10.00', '##############################################################################', '', 'Porto Livre Games', 'https://www.portolivregames.com/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '9.50*', '##############################################################################', '', 'ProNerd', 'https://www.lojapronerd.com/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '10.00', '##############################################################################', '', 'Konklave FunStore', 'https://www.konklavecards.com/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '9.50*', '##############################################################################', '', 'Hive Jogos', 'https://www.hivejogos.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '11.75*', '##############################################################################', '', 'Inside Games', 'https://www.insidegamestore.com/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '8.50*', '##############################################################################', '', 'Legion Board & Card Games', 'https://www.legioncg.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '8.50*', '##############################################################################', '', 'Kinoene Cards', 'https://www.kinoenecards.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '10.00*', '##############################################################################', '', 'Basics Cards', 'https://www.basicscards.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '9.90*', '##############################################################################', '', 'Ascens&atilde;o', 'https://www.ascensaocards.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '12.00', '##############################################################################', '', 'Shandalar', 'https://www.shandalar.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '10.00*', '##############################################################################', '', 'You Cards', 'https://www.youcards.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '9.00*', '##############################################################################', '', 'MTG Caxias Cards', 'https://www.mtgcaxias.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '9.00*', '##############################################################################', '', 'Flow Games', 'https://www.flowstore.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '8.90', '##############################################################################', '', 'Taverna Geek', 'https://www.tavernageek.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '9.00', '##############################################################################', '', 'Set7 card games.', 'https://www.ligamagic.com.br/?view=ecom/item&id=114056&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '10.00*', '##############################################################################', '', 'Toca do Quati', 'https://www.lojadoquati.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '12.00*', '##############################################################################', '', 'Hobby Center', 'https://www.hobbycards.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '10.00', '##############################################################################', '', 'Nexus Cards & Games', 'https://www.ligamagic.com.br/?view=ecom/item&id=197586&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '10.00*', '##############################################################################', '', 'Universo Magic', 'https://umtg.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '10.00', '##############################################################################', '', 'RED Jogos', 'https://www.lotustore.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '9.00*', '##############################################################################', '', 'Skull Games', 'https://www.skullgames.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '9.30*', '##############################################################################', '', 'Mulligan Geek Store', 'https://www.mulligangames.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '10.00*', '##############################################################################', '', 'Liga Arena', 'https://www.ligaarena.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '9.90*', '##############################################################################', '', 'Meruru', 'https://www.meruru.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '10.90', '##############################################################################', '', 'Epic Game', 'https://www.epicgame.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '10.00', '##############################################################################', '', 'Lets Collect', 'https://www.letscollect.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '10.00*', '##############################################################################', '', 'Loja Blood Moon', 'https://lojabloodmoon.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '10.00*', '##############################################################################', '', 'Loja Caverna do Drag&atilde;o', 'https://www.lojacavernadodragao.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '8.50*', '##############################################################################', '', 'CL TCG', 'https://www.clmtg.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '10.00*', '##############################################################################', '', 'LOJA CALABOU&Ccedil;O - HOBBIES E COLECION&Aacute;VEIS', 'https://www.lojacalabouco.com/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '9.00*', '##############################################################################', '', 'DeckMasterGames', 'https://www.deckmastergames.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '9.30*', '##############################################################################', '', 'MTG Cards Games', 'https://www.mtgcardsgames.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '11.00*', '##############################################################################', '', 'WCG - World Card Games', 'https://www.worldcardgames.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '10.00', '##############################################################################', '', 'Loja Grimorium', 'https://lojagrimorium.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '9.99', '##############################################################################', '', 'VAULT', 'https://www.ligamagic.com.br/?view=ecom/item&id=45050&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '8.00*', '##############################################################################', '', 'Ilus&otilde;es Industriais', 'https://www.lojailusoes.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '8.00', '##############################################################################', '', 'ManaFix.net', 'https://www.ligamagic.com.br/?view=ecom/item&id=62691&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '10.00*', '##############################################################################', '', 'Magicbembarato', 'https://www.magicbembarato.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '7.00*', '##############################################################################', '', 'Livraria do Infinito - MagicJebb', 'https://www.livrariadoinfinito.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '10.50', '##############################################################################', '', 'Cards Store', 'https://cardsstore.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '8.00*', '##############################################################################', '', 'Nerdz Cards', 'https://www.nerdzcards.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '9.50*', '##############################################################################', '', "Gideon\\'s Palace", 'https://www.gideonspalace.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '9.80**', '##############################################################################', '', 'Cards Of Paradise', 'https://www.ligamagic.com.br/?view=ecom/item&id=26393&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '12.00', '##############################################################################', '', 'Jaw Games', 'https://www.ligamagic.com.br/?view=ecom/item&id=53329&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '10.30', '##############################################################################', '', 'Arena Hobby Store', 'https://www.arenahobbystore.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '10.80*', '##############################################################################', '', 'Arsenal Nerd', 'https://arsenalnerd.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '9.00*', '##############################################################################', '', 'Card Tutor', 'https://www.cardtutor.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '8.00', '##############################################################################', '', 'Vila Celta Hobby Store', 'https://www.vilacelta.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '9.50*', '##############################################################################', '', 'C&uacute;pula do Trov&atilde;o', 'https://cupuladt.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '8.50', '##############################################################################', '', 'Ref&uacute;gio do Drag&atilde;o', 'https://www.refugiododragao.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '8.45*', '##############################################################################', '', 'Rayearth Games', 'https://www.rayearthgames.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '8.60', '##############################################################################', '', 'Magic Store Brasil', 'https://www.magicstorebrasil.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '14.00', '##############################################################################', '', 'Miragem Hobby', 'https://www.miragemhobby.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '15.75*', '##############################################################################', '', 'Nerdz Curitiba', 'https://www.nerdzcuritiba.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '10.50', '##############################################################################', '', 'Cards e Games', 'https://www.cardsegames.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '9.75*', '##############################################################################', '', 'DrawGO. Games', 'https://www.drawgogames.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '9.99*', '##############################################################################', '', 'AnimeToys Sorocaba', 'https://www.animetoyssorocaba.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '11.00', '##############################################################################', '', 'Cabala MtG', 'https://www.ligamagic.com.br/?view=ecom/item&id=15146&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '7.25*', '##############################################################################', '', 'City Class Games', 'https://www.cityclassgames.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '10.90*', '##############################################################################', '', 'Mineral Games', 'https://www.mineralgames.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '9.00*', '##############################################################################', '', 'A Taverna', 'https://atavernapointnerd.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '9.00*', '##############################################################################', '', 'Bazar de Bagd&aacute;', 'https://www.bazardebagda.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '10.00', '##############################################################################', '', 'Tabuleria', 'https://www.tabuleria.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '9.00*', '##############################################################################', '', 'Power9', 'https://www.power9.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '17.00*', '##############################################################################', '', 'Monster Games Cards', 'https://www.monstergamescards.com/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '9.00*', '##############################################################################', '', 'Pi Games', 'https://www.pigamescard.com/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '11.00*', '##############################################################################', '', 'A Loja do Pai', 'https://www.alojadopai.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '9.00', '##############################################################################', '', 'Magic Club', 'https://www.magicclubtcg.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '10.75**', '##############################################################################', '', 'Load or Cast', 'https://loadorcast.com/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '10.00', '##############################################################################', '', 'MoxPlay', 'https://moxplay.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '13.00*', '##############################################################################', '', 'TCGeeK', 'https://www.tcgeek.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '9.50**', '##############################################################################', '', 'Prime MTG', 'https://primemtg.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '9.75*', '##############################################################################', '', 'Elder Dragon Brasil', 'https://elderdragonbrasil.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '12.00*', '##############################################################################', '', 'Pante&atilde;o Games', 'https://www.panteao.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '10.00', '##############################################################################', '', 'Newstation', 'https://newstationtcg.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '10.00*', '##############################################################################', '', 'XPlace', 'https://www.xplace.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '9.50', '##############################################################################', '', 'Neowalkers Geek Store', 'https://www.neowalkers.com/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '11.00*', '##############################################################################', '', 'Tokenlandia Cards', 'https://www.tokenlandiacards.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '9.00', '##############################################################################', '', 'PlayGround', 'https://www.playgroundgames.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '10.00*', '##############################################################################', '', 'Armada Nerd Hobby Store', 'https://www.armadanerdstore.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '10.00*', '##############################################################################', '', 'Condado Card Games', 'https://www.condadocg.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '9.50*', '##############################################################################', '', 'Magic Leste', 'https://www.magicleste.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '8.00*', '##############################################################################', '', 'MTG Brasil', 'https://www.mtgbrasil.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '9.00', '##############################################################################', '', 'Loja Drop1', 'https://www.drop1.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '9.00', '##############################################################################', '', 'Loja de Cartinhas', 'https://lojadecartinhas.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '7.40', '##############################################################################', '', 'Portal', 'https://www.lojaportal.net/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '9.00', '##############################################################################', '', 'Top Deck RN', 'https://www.topdeckrn.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '10.00*', '##############################################################################', '', 'Magic House Games', 'https://www.magichouse.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '9.95*', '##############################################################################', '', 'Taverneiros', 'https://www.ligamagic.com.br/?view=ecom/item&id=52797&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '14.00*', '##############################################################################', '', 'House of Cards - Card Games', 'https://www.houseofcardstcg.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '8.50*', '##############################################################################', '', 'Segura Card & Games', 'https://www.seguracards.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '11.00', '##############################################################################', '', 'Power Up Games', 'https://www.pugames.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '8.00', '##############################################################################', '', 'Goblin Hero Store', 'https://goblinherostore.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '11.00*', '##############################################################################', '', 'Treasure Cards', 'https://www.treasurecards.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '12.90*', '##############################################################################', '', 'Cards Outlet', 'https://www.cardsoutlet.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '6.00*', '##############################################################################', '', 'Tutubahia', 'https://www.ligamagic.com.br/?view=ecom/item&id=127399&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '10.00*', '##############################################################################', '', 'Millennium Cards & Games', 'https://www.millenniumcg.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '13.00', '##############################################################################', '', 'VampireX TCG', 'https://www.vampirextcg.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '10.00*', '##############################################################################', '', 'Multiverso', 'https://www.multiversocards.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '11.00*', '##############################################################################', '', 'Medieval Cards', 'https://www.medievalcards.com/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '9.50*', '##############################################################################', '', 'Chuck TCG', 'https://www.chucktcg.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '8.50*', '##############################################################################', '', 'Livraria de Alexandria', 'https://www.ligamagic.com.br/?view=ecom/item&id=109333&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '12.00', '##############################################################################', '', 'Legends Game Store', 'https://www.legendsgs.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '8.90*', '##############################################################################', '', 'Player`s Stop', 'https://playersstoptcg.com/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '11.50*', '##############################################################################', '', 'Dragon Storm', 'https://www.dragonstorm.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '9.90*', '##############################################################################', '', 'Valhala Store', 'https://www.valhalastore.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '10.00*', '##############################################################################', '', 'Rocky Raccoon', 'https://www.rockyraccoon.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '6.50*', '##############################################################################', '', "Pharaoh\\'s Shop", 'https://pharaohshoptcg.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '9.00*', '##############################################################################', '', 'Reino Magic', 'https://www.reinomagic.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '9.00', '##############################################################################', '', 'Moinho de Vento Geek Store', 'https://www.moinhodeventoloja.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '9.00', '##############################################################################', '', 'Padrinho: Card Store', 'https://www.padrinhocs.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '9.00*', '##############################################################################','', 'Xaracards', 'https://www.ligamagic.com.br/?view=ecom/item&id=200600&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '9.95*', '##############################################################################','', 'Multiverso Cards Comercio de Jogos e Acessorios Lt', 'https://www.multiversocards.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '11.00*', '##############################################################################','', 'Magicdomain', 'https://magicdomain.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '9.49*', '##############################################################################','', 'Bahia Store', 'https://magicbahiastore.com.br/?view=ecom/item&card=', '&tcg=1&utm_source=liga&utm_medium=site&utm_campaign=comparadorMagic', '10.0*', '##############################################################################']
    ###################################################################################################
    #webpage=input("Insira abaixo o endereço virtual do seu deck no site 'Ligamagic'\n")
    req = Request(websiteurl, headers={'User-Agent': 'Mozilla/5.0'})
    page = urlopen(req).read().decode('utf-8')
    ###################################################################################################

    Cards=findall(r"""(?<=<div class='truncate170'>)[1-9][0-9]? <a href="[.]/[?]view=cards/card&card=[-\w ]+(?=" class=')""",page)
    Cards=[Cards[i].split(' <a href="./?view=cards/card&card=') for i in range(len(Cards))]

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

    appendsummary.write("number of cards\tnumber of sites\n"+str(Cardsfull)+"\n"+str(len(GeneralList[0]))+"\n")
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
            for k in range(int(Cards[j][0])):
                toput="\n"+str(GeneralList[1][i][j][k])
                appendsummary.write(toput)
            appendsummary.write("\n"+str(123456780+int(Cards[j][0])))
        if("**" in GeneralList[2][i]):
            part1=(GeneralList[2][i]).replace("*","")
            part2="1.05"
        elif("*" in GeneralList[2][i]):
            part1=(GeneralList[2][i]).replace("*","")
            part2="1.02"
        else:
            part1=GeneralList[2][i]
            part2="1.00"
        toappshipp=("\n"+part1+"\n"+part2)
        appendsummary.write(toappshipp)
    appendsummary.close()
    ###################################################################################################
    ###################################################################################################
    ###################################################################################################
    os.system('xdg-open summary.txt')
    Concatenated=[]
    Concatenated.append(Cards)
    Concatenated.append(GeneralList)
    return(Concatenated)

###################################################################################################
###################################################################################################
###################################################################################################
###################################################################################################
###################################################################################################
###################################################################################################
###################################################################################################
###################################################################################################
###################################################################################################
###################################################################################################

def CreateCromossomes(thecards,thegeneral):
    from random import randint
    newcromossome=[[],0,[]]
    
    for i in range(len(thecards)):
        mlist=[]
        newcromossome[2].append(0)
        for j in range(int(thecards[i][0])):
            toaddrand= randint(0,(len(thegeneral[0])-1))
            numbe=mlist.count(toaddrand)
            newcromossome[0].append(toaddrand)
            if "**" in thegeneral[2][toaddrand]:
                correctedshipp=1.05*(float(thegeneral[1][toaddrand][i][numbe]))
            elif "*" in thegeneral[2][toaddrand]:
                correctedshipp=1.02*(float(thegeneral[1][toaddrand][i][numbe]))
            else:
                correctedshipp=float(thegeneral[1][toaddrand][i][numbe])
            newcromossome[1]+=correctedshipp
            newcromossome[2][i]+=correctedshipp
    settedcromossome=list(set(newcromossome[0]))
    for k in settedcromossome:
        finalshipp=float((thegeneral[2][k]).replace("*",""))
        newcromossome[1]+=finalshipp    
    return(newcromossome)

###################################################################################################
###################################################################################################
###################################################################################################
###################################################################################################
###################################################################################################
###################################################################################################
###################################################################################################
###################################################################################################
###################################################################################################
###################################################################################################

def BreedingProcess(thelist,thecards,thegeneral,theactual):
    from random import randint
    newcromossome=[[],0,[]]
    
    for i in range(len(thecards)):
        mlist=[]
        newcromossome[2].append(0)
        m=0
        for j in range(int(thecards[i][0])):
            toaddrand= randint(0,1)
            if(toaddrand==1):
                toaddrand=thelist[0][0][m+j]
            else:
                toaddrand=thelist[theactual][0][m+j]

            numbe=mlist.count(toaddrand)
            newcromossome[0].append(toaddrand)
            if "**" in thegeneral[2][toaddrand]:
                correctedshipp=1.05*(float(thegeneral[1][toaddrand][i][numbe]))
            elif "*" in thegeneral[2][toaddrand]:
                correctedshipp=1.02*(float(thegeneral[1][toaddrand][i][numbe]))
            else:
                correctedshipp=float(thegeneral[1][toaddrand][i][numbe])
            newcromossome[1]+=correctedshipp
            newcromossome[2][i]+=correctedshipp
        m+=int(thecards[i][0])
    settedcromossome=list(set(newcromossome[0]))
    for k in settedcromossome:
        finalshipp=float((thegeneral[2][k]).replace("*",""))
        newcromossome[1]+=finalshipp    
    return(newcromossome)

###################################################################################################
###################################################################################################
###################################################################################################
###################################################################################################
###################################################################################################
###################################################################################################
###################################################################################################
###################################################################################################
###################################################################################################
###################################################################################################
def Mutation(thelist,thecards,thegeneral,therandom):
    from random import randint

    RandomCard=randint(0,(len(thecards)-1))
    Starter=sum([(int(thecards[i][0])) for i in range(RandomCard)])

    RandomPosition=randint(0,(int(thecards[RandomCard][0]))-1)

    thelist[therandom][0][Starter+RandomPosition]=randint(0,(len(thegeneral[0])-1))
    thelist[therandom][1]-=thelist[therandom][2][RandomCard]
    thelist[therandom][2][RandomCard]=0


    mlist=[]
    for i in range(int(thecards[RandomCard][0])):
        variablee=thelist[therandom][0][Starter+i]
        numbe=mlist.count(variablee)
        if "**" in thegeneral[2][variablee]:
            correctedshipp=1.05*(float(thegeneral[1][variablee][RandomCard][numbe]))
        elif "*" in thegeneral[2][variablee]:
            correctedshipp=1.02*(float(thegeneral[1][variablee][RandomCard][numbe]))
        else:
            correctedshipp=float(thegeneral[1][variablee][RandomCard][numbe])
        thelist[therandom][1]+=correctedshipp
        thelist[therandom][2][RandomCard]+=correctedshipp

    toreplace=thelist[therandom]
    return toreplace



            