class Factory;

extern Factory* gp_Factory;

class Factory
{
private:
    /* data */
public:
    Factory(/* args */);
    ~Factory();
    static Factory o_Factory;
    virtual int CreateEOD(){return 10;};
};