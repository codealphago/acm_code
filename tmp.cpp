$(document).ready(function(){ 
	$.get("a.html",function(data){ //��ʼ��a.html include div#iframe
��������$("#iframe").html(data);
	}); 
	$(function(){
	$('.list-side li').click(function() {
		// �ҳ� li �еĳ����� href(#id)
		var $this = $(this),
		_clickTab = $this.find('a').attr('target'); // �ҵ�����a�е�targer��ֵ
		$.get(_clickTab,function(data){
			$("#iframe").html(data); 
		});
	});
})});
