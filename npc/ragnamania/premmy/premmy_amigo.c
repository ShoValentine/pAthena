prontera,142,289,5	script	Amigo Ragnamania	97,{
	mes "[Amigo]";
	mes "� um prazer ter voc� brincando aqui conosco!";
	next;
	mes "Voc� j� ouviu falar das ^0000FFContas de Doador^000000 do Ragnamania?";
	next;
	mes "Talvez voc� as conhe�a por ^FF0000Conta Premmy^000000, � assim que a maioria aqui as chama. ^^";
	next;
	menu "Sim, J� sou Parceiro Ragnamania.",SouParceiro,"Hum...Ainda n�o.",NaoConheco,"N�o tenho interesse em ter uma.",-;
	mes"Ok! Seja bem vindo ao Ragnamania!!";
	close;	

	SouParceiro:
		if (getgmlevel() < 1) goto L_Enter;
		mes "[Amigo]";
		mes "Wow! Como pude n�o lhe reconhecer!";
		mes "Mil desculpas ^ff0000"+ strcharinfo(0) + "^000000,Prometo prestar mais aten��o.";
		Next;
		warp "sala_premmy",41,38;
		end;
		L_Enter:
			mes "[Amigo]";
			mes "Hum... N�o me lembro de voc�...";
			mes "Sugiro que entre em contato com meu amigo Biali, ou algu�m da equipe de GMs... Pode estar havendo algum mal-entendido.";
			mes "Por favor, n�o nos leve a mal...Mas s� posso deixar entrar quem tem o nome na minha lista... Desculpe-me.";
			close;

	NaoConheco:
		mes "[Amigo]";
		mes "Bem, o Ragnamania tem um custo fixo mensal para se manter online...";
		mes "Atualmente o Ragnamania conta com 3 servidores hosteados no exterior.";
		next;
		mes "[Amigo]";
		mes "Por�m, o Ragnamania vem crescendo a cada dia! e como vov� deve saber,";
		mes "Manter um servidor com as propor��es do Ragnamania custa algum dinheiro todo m�s...";
		next;
		mes "[Amigo]";
		mes "Por isso, foi criado o sistema de ^0000ffContas de Doador^000000...";
		mes "Uma Conta de Doador te d� acesso � ^0000ffPremium Room^000000";
		mes "Uma sala desenvolvida especialmente para aqueles players que colaboram com o Ragnamania.";
		mes "Ou seja, se voc� realizar uma doa��o ao Ragnamania de pelo menos R$5,00";
		mes "O Ragnamania libera seu acesso � Premium Room por um m�s como gratid�o pela sua colabora��o!!";
		next;
		mes "[Amigo]";
		mes "Na premium Room voc� encontrar� NPCs especiais. Eles est�o l� como uma forma de agradecimento �queles que nos ajudam...";
		mes "Voc� ajuda o Ragnamania, e o Ragnamania ajuda voc�... Fant�stico n�o?";
		next;
		mes "[Amigo]";
		mes "Est� curioso pra saber quem te espera l� na Premium Room?!";
		next;
		mes "[Amigo]";
		mes "HUm... Infelizmente eu n�o posso te contar :( ";
		mes "Mas, posso dar uma dica...";
		next;
		mes "[Amigo]";
		mes "Voc� deve ter sentido a falta de alguns NPCs nesta nova vers�o do Ragnamania, n�o �?";
		mes "Pois �! Quem sabe eles n�o est�o l�? hehehe";
		next;
		menu "Wow! Como fa�o pra ter uma Conta de Doador",CPremium,"Legal! Mas agora n�o posso ter uma...",close;
			CPremium:
				mes "[Amigo]";
				mes "Bem, o Ragnamania trabalha com dep�sito em conta...";
				mes "Como eu te disse anteriormente, com R$5,00 doados ao Ragnamania voc� j� recebe sua Conta de Doador";
				next;
				mes "[Amigo]";
				mes "Ela leva em m�dia 24 horas para ser ativada...";
				mes "Voc� d�a, comprova o dep�sito, e n�s transformamos sua conta em uma Conta de Doador!";
				mes "Para tirar melhor suas d�vidas, visite nosso site: www.ragnamania.com.br";
				mes "At� Mais!";
				close;

}