#ifndef MEMORIA_H
#define MEMORIA_H


class Memoria
{
    public:
        Memoria();

        public:

        int *entero;
        float *flotante;
        string *texto;
        bool *boleano;

        virtual ~Memoria();


    protected:
    private:
};

#endif // MEMORIA_H
