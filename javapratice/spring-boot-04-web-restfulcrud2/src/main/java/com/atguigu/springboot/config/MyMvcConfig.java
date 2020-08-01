package com.atguigu.springboot.config;

import com.atguigu.springboot.component.LoginHandlerInterceptor;
import com.atguigu.springboot.component.MyLocaleResolver;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.web.servlet.LocaleResolver;
import org.springframework.web.servlet.config.annotation.InterceptorRegistry;
import org.springframework.web.servlet.config.annotation.ViewControllerRegistry;
import org.springframework.web.servlet.config.annotation.WebMvcConfigurer;
import org.springframework.web.servlet.config.annotation.WebMvcConfigurerAdapter;

/**
 * @Author LC
 * @Date 2020/7/30 22:06
 * @Version 1.0
 */
@Configuration
public class MyMvcConfig extends WebMvcConfigurerAdapter     {

    @Override
    public void addViewControllers (ViewControllerRegistry registry){
        //浏览器发送atguigu请求也来到success页面
        registry.addViewController("/atguigu").setViewName("success");
    }

    @Bean
    //将组件注册在容器
    //所有的webmvcconfigureradapter组件都会一起起作用
    public WebMvcConfigurer webMvcConfigurer(){
        WebMvcConfigurer webMvcConfigurer = new WebMvcConfigurer(){
            @Override
            public void addViewControllers(ViewControllerRegistry registry) {
                registry.addViewController("/").setViewName("/login");
                registry.addViewController("/index.html").setViewName("/login");
                registry.addViewController("main.html").setViewName("/dashboard");
            }

            //注册拦截器

            @Override
            public void addInterceptors(InterceptorRegistry registry) {
                //spring boot已经做好静态资源映射
                registry.addInterceptor(new LoginHandlerInterceptor()).addPathPatterns("/**")
                        .excludePathPatterns("/index.html",
                                "/",
                                "/user/login",
                                "/asserts/**",
                                "/webjars/**",
                                "/**");
            }
        };
        return webMvcConfigurer;
    }


    @Bean
    public LocaleResolver localeResolver(){
       return new MyLocaleResolver();
   }
}
