$(document).ready(function () {
    $('table').on('click','.deletespan',function(){
        var tr=$(this).parent().parent();
        var id=tr.children('input[type=hidden]').val();

        $.ajax({
            url: '/material/delete',
            type: 'post',
            data:{materialID:id},
            success: function (res) {
                if(res.status=='success'){
                    tr.remove();
                    alert(res.status);
                }

            }
        });
    });

    $('.btn1').click(function(){
        var text=$(this).prev().val();
        if(typeof text == "undefined" || text == null || text == ""){
            alert("查询不能为空");
            return ;
        }

        $.ajax({
            url: '/guidingbook/findByName',
            type: 'post',
            data:{guidingBookName:text},
            success: function (res) {
                $('#tbody').remove();
                var html="<tbody>";
                for (var i=0;i<res.data.length;i++)
                {
                    html+="<tr><input value='"+res.data[i].guidingBookId+"' type='hidden'><td>"+res.data[i].guidingBookName+"</td>";
                    html+="<td><span><a href='"+res.data[i].guidingBookUrl+"'>11</a></span></td>";
                    html+="<td><span>"+res.data[i].uploadDate+"</span></td>";
                    html+="<td><span id='changeFile'>修改</span><span class='deletespan'>删除</span></td>";
                    html+="</tr>";
                }
                html+="</tbody>";
                $("table").append(html);

            }
        });
    });

    $('.btn2').click(function(){

        $(this).prev().prev().val('');

    });

    $('.addspan').click(function(){
        var name=$('#guidingBookName').val();
        var formData = new FormData();
        formData.append("file",$('#file')[0].files[0]);
        formData.append("guidingBookName",name);
        $.ajax({
            encType: 'multipart/form-data',
            url: '/guidingbook/fileUpload',
            type: 'POST',
            data:formData,
            processData : false,  //必须false才会避开jQuery对 formdata 的默认处理
            contentType : false,
            success: function (res) {


            }
        });
    });
});