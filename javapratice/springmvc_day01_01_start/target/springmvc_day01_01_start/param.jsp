<%--
  Created by IntelliJ IDEA.
  User: Lucy
  Date: 2020/3/18
  Time: 17:07
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>param</title>
</head>
<body>
    <form action="/springmvc_day01_01_start_war/param/saveAccount" method="post">
        姓名：<input type="text" name="username" /><br/>
        密码：<input type="password" name="password" /><br/>
        金额：<input type="text" name="money"><br/>
        用户姓名：<input type="text" name="user.name"><br/>
        用户年龄：<input type="text" name="user.age"><br/>
        <input type="submit" name="提交" />
    </form>
</body>
</html>
