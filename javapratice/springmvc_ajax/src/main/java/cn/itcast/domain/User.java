package cn.itcast.domain;

public class User {
    private String name;
    private int age;
    private String Sex;

    public String getName() {
        return name;
    }

    public int getAge() {
        return age;
    }

    public String getSex() {
        return Sex;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public void setSex(String sex) {
        Sex = sex;
    }

    @Override
    public String toString() {
        return "User{" +
                "name='" + name + '\'' +
                ", age=" + age +
                ", Sex='" + Sex + '\'' +
                '}';
    }

    public User() {
    }

    public User(String name, int age, String sex) {
        this.name = name;
        this.age = age;
        Sex = sex;
    }
}
