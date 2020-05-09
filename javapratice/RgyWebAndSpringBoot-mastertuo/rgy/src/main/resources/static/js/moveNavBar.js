$(function(){
	var ID;
	$(".Top1 a").click(function(){
		$(".Top1 a.active").removeClass("active");
		//$(ID).hide();
		for(var i=1;i<=5;i++)
		$(".Top2_"+i).css("display","none");
		$(this).addClass("active");
		ID = ".Top2_"+$(this).attr('id');
		//$(ID).show();
		$(ID).css("display","block");
	});
	
})