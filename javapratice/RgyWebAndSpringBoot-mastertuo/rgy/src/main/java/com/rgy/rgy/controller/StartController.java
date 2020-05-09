package com.rgy.rgy.controller;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.servlet.ModelAndView;

import java.util.ArrayList;
import java.util.List;

/**
 * @Author: gaoyk
 * @Date: 2019/11/19 19:17
 */
@Controller
@RequestMapping("/start")
public class StartController {

    @RequestMapping("/")
    public String star(){
        return "index";
    }
    @RequestMapping("/down")
    public String star2(){
        return "multifile";
    }

    @RequestMapping("/login")
    public String login(){
        return "/login";
    }

    @RequestMapping("/test")
    public String hello(){

        return "laji";
    }
}
