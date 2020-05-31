package com.atguigu.springboot.controller;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.bind.annotation.RestController;

/**
 * @Author LC
 * @Date 2020/5/23 21:44
 * @Version 1.0
 * 这个方法的数据直接返回给浏览器
 */

//@ResponseBody
//@Controller
    @RestController
public class HelloController {
    @RequestMapping("/hello")
    public String hello(){
        return "hello world quick!";
    }
}
