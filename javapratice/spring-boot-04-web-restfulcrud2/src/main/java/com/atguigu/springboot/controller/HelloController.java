package com.atguigu.springboot.controller;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

import java.util.Arrays;
import java.util.Map;

/**
 * @Author LC
 * @Date 2020/5/29 21:03
 * @Version 1.0
 */

@Controller
public class HelloController {
    @ResponseBody
    @RequestMapping("/hello")
    public String hello(){
            return "hello world";
    }

    //查出一些数据，在页面展示
    @RequestMapping("success")
    public String success(Map<String,Object> map){
            map.put("hello","<h1>你好</h1>");
            map.put("users", Arrays.asList("zhangsan","lisi","wangwu"));
            return "success";
    }

    //设置不管访问根路径还是index都访问index页面
//    @RequestMapping({"/","/index.html"})
//    public String index(){
//        return "index";
//    }
}
